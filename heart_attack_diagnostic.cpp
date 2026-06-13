/*
 * ============================================================================
 *  Heart Attack Diagnostic & Hospital Management System
 * ============================================================================
 *  Author  : Michael
 *  Language: C++17
 *  Platform: Cross-platform (Windows / Linux / macOS)
 *
 *  Description:
 *    A console-based hospital management system for heart-attack risk
 *    assessment.  It supports three roles — Patient (Client), Doctor, and
 *    Administrator — and implements a complete diagnostic pipeline:
 *      • Patient registration & appointment booking
 *      • Troponin-based cardiac risk scoring
 *      • Blood-glucose / diabetes screening (FPG + OGTT)
 *      • Blood-pressure classification
 *      • Personalised medicine & diet recommendations
 *      • Billing / medicine ordering
 *      • Admin CRUD on patient records and staff management
 *
 *  Build:
 *    cmake -S . -B build && cmake --build build
 *    -- or --
 *    g++ -std=c++17 -o heart_diagnostic heart_attack_diagnostic.cpp
 * ============================================================================
 */

// ── Standard headers ────────────────────────────────────────────────────────
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <thread>
#include <limits>

// ── Platform-specific terminal helpers ──────────────────────────────────────
#ifdef _WIN32
  #include <windows.h>
  #include <conio.h>
  static inline void platform_sleep(int seconds)   { Sleep(static_cast<DWORD>(seconds) * 1000); }
  static inline void platform_sleep_ms(int ms)     { Sleep(static_cast<DWORD>(ms)); }
  static inline void clear_screen()                { system("cls"); }
  static inline char get_char()                    { return static_cast<char>(_getch()); }
#else
  #include <unistd.h>
  #include <termios.h>
  static inline void platform_sleep(int seconds)   { ::sleep(static_cast<unsigned>(seconds)); }
  static inline void platform_sleep_ms(int ms)     { std::this_thread::sleep_for(std::chrono::milliseconds(ms)); }
  static inline void clear_screen()                { std::cout << "\033[2J\033[H" << std::flush; }
  static inline char get_char()
  {
      struct termios oldt, newt;
      tcgetattr(STDIN_FILENO, &oldt);
      newt = oldt;
      newt.c_lflag &= static_cast<tcflag_t>(~(ICANON | ECHO));
      tcsetattr(STDIN_FILENO, TCSANOW, &newt);
      char ch = static_cast<char>(getchar());
      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
      return ch;
  }
#endif

using namespace std;

// ── Compile-time constants ───────────────────────────────────────────────────
// NOTE: In a production system these would live in a config file or
//       environment variable; never hard-code credentials in source.
static const char* SYSTEM_LOGIN_ID = "software1";
static const char* SYSTEM_PASSWORD = "software2050";
static const char* BANNER_TOP =
    "\t\t\t\t WELCOME TO MICHAEL'S HEALTH CENTER\n"
    "\t\t\t\t\t Your Health, Our Priority!\n";
static const char* DIVIDER =
    "─────────────────────────────────────────────────────────────────────────\n";

// ── Globals (intentionally minimal) ─────────────────────────────────────────

// ── Forward declarations ─────────────────────────────────────────────────────
class HeartAttack;
class SecuredLogin;
class Issues;
class Doctor;
class Bill;
class Client;
class Administration;
class Discussion;
class FinalReport;
class Quick;
class Diet;

// These are defined after Quick and Diet, used in mainMenu()
static void run_quick_checkup();
static void run_diet_planner();

// ── Utility helpers ──────────────────────────────────────────────────────────
static void print_banner()
{
    cout << BANNER_TOP;
    cout << DIVIDER;
}

static void typewriter(const char* text, int delay_ms = 12)
{
    for (int i = 0; text[i] != '\0'; ++i)
    {
        cout << text[i] << flush;
        platform_sleep_ms(delay_ms);
    }
}

static void safe_getline(char* buf, int size)
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(buf, size);
}

static string blood_group_name(int idx)
{
    static const char* groups[] = {"A+","A-","B+","B-","O+","O-","AB+","AB-"};
    if (idx >= 0 && idx < 8) return groups[idx];
    return "O+";
}

// ─────────────────────────────────────────────────────────────────────────────
//  Class declarations
// ─────────────────────────────────────────────────────────────────────────────

class Issues
{
public:
    int id;
    int vision;
    int chestDiscomfort;
    int bodyWeakness;
    int breathShortness;
    char bloodGroup[3];
    int dizziness;
    int fatigue;
    char familyHistory;     // 'Y' / 'N'
    char weightLoss;        // 'Y' / 'N'
    char nutritionStatus;   // 'Y' / 'N'  (ate in last 3 hrs)
    float troponinLevel;
    float bloodPressureSystolic;
    float bloodPressureDiastolic;
    float fastingGlucose;   // FPG  (mg/dl)
    float ogttGlucose;      // OGTT (mg/dl)
};

class Doctor
{
public:
    int patientId;
    int doctorId;
    struct Date { int d, m, y; } appointmentDate;
};

class Bill
{
public:
    int patientId;
    int billId;
    float total;
};

class Client
{
public:
    int buyId;
    char updateRequest[2000];
    char complaint[2000];

    void updateMyRecord();
    void buyMedicine();
    void checkMedicines();
    void viewDiseaseLevel();
    void viewMessages();
    void registerComplaint();
    void changeDoctor();
};

class Administration
{
public:
    int    staffId;
    char   staffName[30];
    char   staffUserId[30];
    char   staffPassword[30];
    long long int staffPhone;
    int    medicineId;
    char   medicineName[300];
    float  medicinePrice;
    char   replyBuffer[200];

    void   signUp();
    void   addMedicine();
    void   viewComplaints();
    void   adminDuty();
    void   countRecords();
};

class Discussion
{
public:
    int  id;
    char name[20];
    char inquiry[200000];
    char reply[200000];
};

class FinalReport
{
public:
    int  id;
    char riskLevel; // 'L' Low, 'M' Medium, 'H' High
};

// ─────────────────────────────────────────────────────────────────────────────
//  HeartAttack — the main application controller
// ─────────────────────────────────────────────────────────────────────────────

class HeartAttack
{
    int           id;
    char          name[200];
    int           age;
    float         height;
    float         weight;
    char          sex;
    long long int phone;

public:
    // Public data needed by friends
    friend class Doctor;
    friend class Issues;
    friend class Administration;
    friend class Client;
    friend class Quick;

    // Menu / navigation
    void mainMenu();
    void clientMenu();

    // CRUD
    void enterPatientData();
    void showDoctorList();
    void deleteRecord();
    void updateRecord();
    void searchRecord();
    int  displayAll(int, int);

    // Diagnostics
    void runDiagnosticTest();
    int  generateReport();
    void preReport();

    // Admin
    void adminMenu();
    void adminLogin();
    void replyToInquiry();

    // Client features
    void clientSecuredLogin();

    // Misc
    void postInquiry();
    void viewInquiryReplies();
    void aboutDeveloper();
};

// ─────────────────────────────────────────────────────────────────────────────
//  Global instances
// ─────────────────────────────────────────────────────────────────────────────
static HeartAttack    g_app;
static Issues         g_issues;
static Doctor         g_doctor;
static Client         g_client;
static Administration g_admin;
static Discussion     g_discussion;

// File stream handles (global to match original architecture)
static fstream fin, fout, fturndoc, ftemp, fadmin, fcross, fsum;

// ─────────────────────────────────────────────────────────────────────────────
//  SecuredLogin — system-level authentication
// ─────────────────────────────────────────────────────────────────────────────

class SecuredLogin
{
public:
    bool authenticate()
    {
        clear_screen();
        char loginId[20]  = {0};
        char password[20] = {0};

        print_banner();
        typewriter("\n Enter Login ID: ");
        cin >> loginId;

        if (strcmp(loginId, SYSTEM_LOGIN_ID) != 0)
        {
            cout << "\n Invalid Login ID.\n";
            return false;
        }

        typewriter("\n Enter Password: ");
        int i = 0;
        char ch;
        while (i < 19)
        {
            ch = get_char();
            if (ch == '\r' || ch == '\n') break;
            if (ch == '\b' || ch == 127)
            {
                if (i > 0) { cout << "\b \b"; --i; }
                continue;
            }
            cout << '*' << flush;
            password[i++] = ch;
        }
        password[i] = '\0';
        cout << '\n';

        if (strcmp(password, SYSTEM_PASSWORD) == 0)
        {
            cout << "\n Login Successful!\n";
            platform_sleep(1);
            return true;
        }
        cout << "\n Incorrect password.\n";
        return false;
    }
} g_securedLogin;

// ─────────────────────────────────────────────────────────────────────────────
//  HeartAttack — method implementations
// ─────────────────────────────────────────────────────────────────────────────

void HeartAttack::mainMenu()
{
    bool running = true;
    while (running)
    {
        clear_screen();
        print_banner();
        cout << "\n"
             << "  [1] Patient Portal\n"
             << "  [2] Admin Portal\n"
             << "  [3] Post an Inquiry\n"
             << "  [4] View Inquiry Replies\n"
             << "  [5] Quick Checkup\n"
             << "  [6] Diet Planner\n"
             << "  [7] Log Out\n"
             << "  [8] Exit\n"
             << "\n  Your choice: ";

        int ch;
        cin >> ch;

        switch (ch)
        {
        case 1: clientMenu();   break;
        case 2:
            adminLogin();
            break;
        case 3: postInquiry();  break;
        case 4: viewInquiryReplies(); break;
        case 5: run_quick_checkup(); break;
        case 6: run_diet_planner();  break;
        case 7:
            cout << "\n Logging out...\n";
            platform_sleep(1);
            if (!g_securedLogin.authenticate())
                cout << "\n Re-authentication failed.\n";
            break;
        case 8:
            cout << "\n Goodbye!\n";
            platform_sleep(1);
            running = false;
            break;
        default:
            cout << "\n Invalid choice. Try again.\n";
            platform_sleep(1);
        }
    }
}

void HeartAttack::clientMenu()
{
    clear_screen();
    print_banner();

    bool back = false;
    while (!back)
    {
        clear_screen();
        print_banner();
        cout << "\n"
             << "  [1] Register Patient\n"
             << "  [2] Book Appointment\n"
             << "  [3] View All Patients\n"
             << "  [4] Run Diagnostic Test\n"
             << "  [5] Pre-Report\n"
             << "  [6] Final Report\n"
             << "  [7] Patient Login\n"
             << "  [8] About Developer\n"
             << "  [9] Back\n"
             << "\n  Your choice: ";

        int ch;
        cin >> ch;

        switch (ch)
        {
        case 1: enterPatientData();  break;
        case 2: showDoctorList();    break;
        case 3: displayAll(10, 20);  break;
        case 4: runDiagnosticTest(); break;
        case 5: preReport();         break;
        case 6: generateReport();    break;
        case 7: clientSecuredLogin();break;
        case 8: aboutDeveloper();    break;
        case 9: back = true;         break;
        default:
            cout << "\n Invalid choice.\n";
            platform_sleep(1);
        }
    }
}

void HeartAttack::enterPatientData()
{
    int num = 0;
    fout.open("patients.dat", ios::app | ios::binary);
    clear_screen();
    print_banner();

    cout << "\n How many patients to register? ";
    cin >> num;

    for (int i = 0; i < num; ++i)
    {
        clear_screen();
        print_banner();
        cout << "\n Patient " << (i + 1) << " of " << num << "\n" << DIVIDER;

        cout << " Patient ID  : "; cin >> id;
        cout << " Name        : "; safe_getline(name, sizeof(name));
        cout << " Age         : "; cin >> age;
        cout << " Sex (M/F)   : "; cin >> sex;
        cout << " Height (cm) : "; cin >> height;
        cout << " Weight (kg) : "; cin >> weight;
        cout << " Phone no.   : "; cin >> phone;

        fout.write(reinterpret_cast<char*>(this), sizeof(*this));
        cout << "\n Patient registered successfully.\n";
        platform_sleep(1);
    }
    fout.close();
}

int HeartAttack::displayAll(int /*a*/, int /*b*/)
{
    fin.open("patients.dat", ios::in | ios::binary);
    clear_screen();
    print_banner();
    cout << "\n" << left
         << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(6)  << "Age"
         << setw(6)  << "Sex"
         << setw(10) << "Height"
         << setw(10) << "Weight" << "\n"
         << DIVIDER;

    while (fin.read(reinterpret_cast<char*>(&g_app), sizeof(g_app)))
    {
        cout << setw(10) << g_app.id
             << setw(20) << g_app.name
             << setw(6)  << g_app.age
             << setw(6)  << g_app.sex
             << setw(10) << g_app.height
             << setw(10) << g_app.weight << "\n";
    }
    fin.close();
    cout << "\n Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}

void HeartAttack::searchRecord()
{
    clear_screen();
    fin.open("patients.dat", ios::in | ios::binary);
    int targetId;
    cout << "\n Enter Patient ID: ";
    cin >> targetId;

    bool found = false;
    while (fin.read(reinterpret_cast<char*>(&g_app), sizeof(g_app)))
    {
        if (g_app.id == targetId)
        {
            found = true;
            break;
        }
    }
    fin.close();

    if (found)
    {
        cout << "\n" << DIVIDER
             << " ID: " << g_app.id << "  Name: " << g_app.name
             << "  Age: " << g_app.age << "  Sex: " << g_app.sex
             << "  Height: " << g_app.height << "  Weight: " << g_app.weight
             << "\n" << DIVIDER;
    }
    else
        cout << "\n Patient ID not found.\n";

    cout << "\n Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void HeartAttack::runDiagnosticTest()
{
    clear_screen();
    print_banner();

    fin.open("patients.dat",  ios::in  | ios::binary);
    fout.open("issues.dat",   ios::app | ios::binary);
    fturndoc.open("appointments.dat", ios::in | ios::binary);

    int targetId;
    cout << "\n Enter Patient ID: ";
    cin >> targetId;

    bool patientFound = false;
    while (fin.read(reinterpret_cast<char*>(&g_app), sizeof(g_app)))
    {
        if (g_app.id == targetId) { patientFound = true; break; }
    }

    if (!patientFound)
    {
        cout << "\n Patient not found.\n";
        fin.close(); fout.close(); fturndoc.close();
        return;
    }

    int dd, mm, yyyy;
    cout << "\n Enter today's date (dd mm yyyy): ";
    cin >> dd >> mm >> yyyy;

    bool appointmentFound = false;
    while (fturndoc.read(reinterpret_cast<char*>(&g_doctor), sizeof(g_doctor)))
    {
        if (g_doctor.patientId == targetId &&
            g_doctor.appointmentDate.d == dd &&
            g_doctor.appointmentDate.m == mm &&
            g_doctor.appointmentDate.y == yyyy)
        {
            appointmentFound = true;
            break;
        }
    }

    if (!appointmentFound)
    {
        cout << "\n No appointment found for this date.\n";
        fin.close(); fout.close(); fturndoc.close();
        return;
    }

    g_issues.id = targetId;
    cout << "\n Patient: " << g_app.name << "\n" << DIVIDER;
    cout << " Answer each question (3=High, 2=Medium, 1=Low, 0=None)\n\n";

    cout << " 1. Chest discomfort/pain          : "; cin >> g_issues.chestDiscomfort;
    cout << " 2. Increased hunger / weakness    : "; cin >> g_issues.bodyWeakness;
    cout << " 3. Frequent urination             : "; cin >> g_issues.breathShortness;
    cout << " 4. Dizziness                      : "; cin >> g_issues.dizziness;
    cout << " 5. Fatigue                        : "; cin >> g_issues.fatigue;
    cout << " 6. Vision problems                : "; cin >> g_issues.vision;
    cout << " 7. Recent weight loss (Y/N)       : "; cin >> g_issues.weightLoss;
    cout << " 8. Family history of heart attack (Y/N): "; cin >> g_issues.familyHistory;

    cout << "\n [Simulating blood draw...]\n";
    platform_sleep(2);
    cout << " [Analysis complete]\n\n";

    cout << " Ate in the past 3 hours? (Y/N)   : "; cin >> g_issues.nutritionStatus;
    cout << " Troponin level (AQT90 reading)   : "; cin >> g_issues.troponinLevel;
    cout << " Blood pressure systolic  (mmHg)  : "; cin >> g_issues.bloodPressureSystolic;
    cout << " Blood pressure diastolic (mmHg)  : "; cin >> g_issues.bloodPressureDiastolic;
    cout << " Fasting plasma glucose (FPG mg/dl): "; cin >> g_issues.fastingGlucose;
    cout << " OGTT glucose (mg/dl)             : "; cin >> g_issues.ogttGlucose;

    fout.write(reinterpret_cast<char*>(&g_issues), sizeof(g_issues));
    cout << "\n Test data recorded. Report will be ready shortly.\n";
    platform_sleep(2);

    fin.close(); fout.close(); fturndoc.close();
}

int HeartAttack::generateReport()
{
    clear_screen();
    print_banner();

    fin.open("patients.dat", ios::in | ios::binary);
    fout.open("issues.dat",  ios::in | ios::binary);

    int targetId;
    cout << "\n Enter Patient ID: ";
    cin >> targetId;

    bool patientFound = false, issueFound = false;
    while (fin.read(reinterpret_cast<char*>(&g_app), sizeof(g_app)))
        if (g_app.id == targetId) { patientFound = true; break; }

    while (fout.read(reinterpret_cast<char*>(&g_issues), sizeof(g_issues)))
        if (g_issues.id == targetId) { issueFound = true; break; }

    fin.close(); fout.close();

    if (!patientFound || !issueFound)
    {
        cout << "\n No test data found for this patient.\n";
        return -1;
    }

    // ── Print report ──────────────────────────────────────────────────────
    cout << "\n" << DIVIDER
         << " DIAGNOSTIC REPORT\n" << DIVIDER
         << " Patient : " << g_app.name
         << "  |  Age: " << g_app.age
         << "  |  Sex: " << g_app.sex << "\n"
         << DIVIDER << "\n";

    // Symptom scores
    auto level_str = [](int v) -> const char* {
        if (v == 0) return "None";
        if (v == 1) return "Low";
        if (v == 2) return "Medium";
        return "High";
    };
    cout << " Chest discomfort  : " << level_str(g_issues.chestDiscomfort) << "\n"
         << " Body weakness     : " << level_str(g_issues.bodyWeakness)    << "\n"
         << " Dizziness         : " << level_str(g_issues.dizziness)       << "\n"
         << " Fatigue           : " << level_str(g_issues.fatigue)         << "\n"
         << " Breathing         : " << level_str(g_issues.breathShortness) << "\n"
         << " Vision            : " << level_str(g_issues.vision)          << "\n"
         << " Family history    : " << g_issues.familyHistory              << "\n\n";

    // Blood pressure
    cout << " Blood Pressure    : " << g_issues.bloodPressureSystolic
         << "/" << g_issues.bloodPressureDiastolic << " mmHg  → ";
    if (g_issues.bloodPressureSystolic > 140)
        cout << "HIGH (Hypertension)\n";
    else if (g_issues.bloodPressureSystolic >= 120)
        cout << "Normal range\n";
    else
        cout << "Low (Hypotension)\n";

    // Blood metrics (simulated lab results)
    srand(static_cast<unsigned>(time(nullptr)));
    int   bgIdx       = rand() % 8;
    float bloodCount  = static_cast<float>(rand() % 4000 + 7000);
    float hemoglobin  = static_cast<float>(rand() % 8  + 10);
    float cholesterol = static_cast<float>(rand() % 90 + 150);

    cout << "\n─── Lab Results ───────────────────────────────────────────────────────\n"
         << " Blood Group       : " << blood_group_name(bgIdx) << "\n"
         << " WBC Count         : " << bloodCount << " cells/μL  → "
         << (bloodCount < 4500 ? "Low\n" : bloodCount > 11000 ? "High\n" : "Normal\n")
         << " Haemoglobin       : " << hemoglobin << " g/dL  → "
         << (hemoglobin < 12 ? "Low (anaemia risk)\n" : hemoglobin > 17 ? "Elevated\n" : "Normal\n")
         << " Cholesterol (LDL) : " << cholesterol << " mg/dL  → ";
    if (cholesterol <= 100)        cout << "Optimal\n";
    else if (cholesterol <= 129)   cout << "Near Optimal\n";
    else if (cholesterol <= 159)   cout << "Borderline High\n";
    else if (cholesterol <= 189)   cout << "High\n";
    else                           cout << "Very High\n";

    // Glucose
    float riskScore = 0;
    cout << "\n─── Glucose Tests ─────────────────────────────────────────────────────\n"
         << " FPG  (" << g_issues.fastingGlucose << " mg/dL)  : ";
    if      (g_issues.fastingGlucose < 100)  { cout << "Normal\n"; }
    else if (g_issues.fastingGlucose < 126)  { cout << "Pre-diabetic\n"; riskScore += 1; }
    else                                      { cout << "Diabetic (elevated MI risk)\n"; riskScore += 2; }

    cout << " OGTT (" << g_issues.ogttGlucose  << " mg/dL)  : ";
    if      (g_issues.ogttGlucose < 140)  { cout << "Normal\n"; }
    else if (g_issues.ogttGlucose < 200)  { cout << "Pre-diabetic\n"; riskScore += 1; }
    else                                   { cout << "Diabetic (elevated MI risk)\n"; riskScore += 2; }

    // Troponin — the key cardiac biomarker
    cout << "\n─── Troponin (AQT90 FLEX) ─────────────────────────────────────────────\n"
         << " Level: " << g_issues.troponinLevel << " ng/mL  → ";
    if      (g_issues.troponinLevel < 0.04)  { cout << "Normal — no acute MI indicators\n"; }
    else if (g_issues.troponinLevel < 0.40)  { cout << "Elevated — possible cardiac injury (Type 2 MI)\n"; riskScore += 2; }
    else                                      { cout << "Critically high — acute MI highly probable\n";     riskScore += 4; }

    // Symptom risk contribution
    int symptomTotal = g_issues.chestDiscomfort + g_issues.dizziness +
                       g_issues.fatigue + g_issues.bodyWeakness + g_issues.breathShortness;
    if (symptomTotal >= 8) riskScore += 2;
    else if (symptomTotal >= 4) riskScore += 1;
    if (g_issues.familyHistory == 'Y' || g_issues.familyHistory == 'y') riskScore += 1;

    // ── Final verdict ─────────────────────────────────────────────────────
    cout << "\n" << DIVIDER
         << " RISK ASSESSMENT\n" << DIVIDER;
    if (riskScore == 0)
        cout << " Result  : LOW RISK — No significant cardiac markers present.\n"
             << " Advice  : Maintain a healthy lifestyle. Annual check-up recommended.\n";
    else if (riskScore <= 3)
        cout << " Result  : MODERATE RISK — Some elevated markers detected.\n"
             << " Advice  : Consult a cardiologist within 2 weeks. Lifestyle changes advised.\n";
    else if (riskScore <= 5)
        cout << " Result  : HIGH RISK — Multiple elevated markers.\n"
             << " Advice  : Seek medical attention soon. Cardiac monitoring recommended.\n";
    else
        cout << " Result  : CRITICAL — Acute myocardial infarction highly likely.\n"
             << " Advice  : SEEK EMERGENCY CARE IMMEDIATELY.\n";

    cout << DIVIDER
         << " * This report is for informational purposes only.\n"
         << "   Always consult a qualified physician for diagnosis.\n"
         << DIVIDER << "\n";

    cout << " Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return static_cast<int>(riskScore);
}

void HeartAttack::preReport()
{
    clear_screen();
    print_banner();

    fin.open("patients.dat",      ios::in | ios::binary);
    fturndoc.open("appointments.dat", ios::in | ios::binary);

    int targetId;
    cout << "\n Enter Patient ID: ";
    cin >> targetId;

    bool pFound = false, dFound = false;
    while (fin.read(reinterpret_cast<char*>(&g_app), sizeof(g_app)))
        if (g_app.id == targetId) { pFound = true; break; }
    while (fturndoc.read(reinterpret_cast<char*>(&g_doctor), sizeof(g_doctor)))
        if (g_doctor.patientId == targetId) { dFound = true; break; }

    fin.close(); fturndoc.close();

    if (!pFound || !dFound)
    {
        cout << "\n No appointment found for this patient.\n";
        return;
    }

    static const char* docNames[] = {"Dr. Philip","Dr. Ben","Dr. Sarah","Dr. Esther","Dr. Joseph"};
    int di = g_doctor.doctorId - 1;

    cout << "\n" << DIVIDER
         << " PRE-REPORT\n" << DIVIDER
         << " Name      : " << g_app.name << "\n"
         << " Age       : " << g_app.age  << "\n"
         << " Sex       : " << g_app.sex  << "\n"
         << " Phone     : " << g_app.phone<< "\n"
         << " Appt Date : " << g_doctor.appointmentDate.d
         << "/" << g_doctor.appointmentDate.m
         << "/" << g_doctor.appointmentDate.y << "\n"
         << " Doctor    : " << (di >= 0 && di < 5 ? docNames[di] : "N/A") << "\n"
         << DIVIDER;

    cout << "\n Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void HeartAttack::showDoctorList()
{
    clear_screen();
    print_banner();
    fin.open("patients.dat", ios::in | ios::binary);
    fturndoc.open("appointments.dat", ios::app | ios::binary);

    int targetId;
    cout << "\n Enter Patient ID: ";
    cin >> targetId;

    bool found = false;
    while (fin.read(reinterpret_cast<char*>(&g_app), sizeof(g_app)))
        if (g_app.id == targetId) { found = true; break; }

    if (!found)
    {
        cout << "\n Patient not found.\n";
        fin.close(); fturndoc.close();
        return;
    }

    cout << "\n Patient: " << g_app.name << "\n\n";

    bool booked = false;
    while (!booked)
    {
        clear_screen();
        print_banner();
        cout << "\n─── Available Doctors ──────────────────────────────────────────────────\n"
             << " ID  Doctor         Timings          Day    Fees\n"
             << " 1   Dr. Philip     10:00am–12:00pm  Mon    $600\n"
             << " 2   Dr. Ben        05:00pm–07:00pm  Tue    $500\n"
             << " 3   Dr. Sarah      11:00am–01:00pm  Wed    $700\n"
             << " 4   Dr. Esther     11:00am–02:00pm  Thu    $900\n"
             << " 5   Dr. Joseph     05:00pm–08:00pm  Fri    $550\n"
             << "────────────────────────────────────────────────────────────────────────\n"
             << "\n Doctor choice (1-5): ";

        int choice;
        cin >> choice;
        if (choice < 1 || choice > 5) { cout << "\n Invalid choice.\n"; continue; }

        int dd, mm, yyyy;
        cout << " Appointment date (dd mm yyyy): ";
        cin >> dd >> mm >> yyyy;

        g_doctor.patientId              = targetId;
        g_doctor.doctorId               = choice;
        g_doctor.appointmentDate.d      = dd;
        g_doctor.appointmentDate.m      = mm;
        g_doctor.appointmentDate.y      = yyyy;

        fturndoc.write(reinterpret_cast<char*>(&g_doctor), sizeof(g_doctor));
        cout << "\n Appointment confirmed for " << dd << "/" << mm << "/" << yyyy << "\n";
        platform_sleep(2);
        booked = true;
    }

    fin.close();
    fturndoc.close();
}

void HeartAttack::deleteRecord()
{
    clear_screen();
    print_banner();

    displayAll(0, 0);

    int targetId;
    cout << "\n Enter Patient ID to delete: ";
    cin >> targetId;

    fin.open("patients.dat", ios::in | ios::binary);
    fout.open("patients_tmp.dat", ios::out | ios::binary);

    bool deleted = false;
    while (fin.read(reinterpret_cast<char*>(&g_app), sizeof(g_app)))
    {
        if (g_app.id == targetId) { deleted = true; continue; }
        fout.write(reinterpret_cast<char*>(&g_app), sizeof(g_app));
    }
    fin.close(); fout.close();

    if (deleted)
    {
        remove("patients.dat");
        rename("patients_tmp.dat", "patients.dat");
        cout << "\n Record deleted.\n";
    }
    else
    {
        remove("patients_tmp.dat");
        cout << "\n Record not found.\n";
    }
    platform_sleep(2);
}

void HeartAttack::updateRecord()
{
    clear_screen();
    print_banner();

    int targetId;
    cout << "\n Enter Patient ID to update: ";
    cin >> targetId;

    fin.open("patients.dat", ios::in | ios::binary);
    fout.open("patients_tmp.dat", ios::out | ios::binary);

    bool found = false;
    while (fin.read(reinterpret_cast<char*>(&g_app), sizeof(g_app)))
    {
        if (g_app.id == targetId)
        {
            found = true;
            cout << " New name   : "; safe_getline(g_app.name, sizeof(g_app.name));
            cout << " New age    : "; cin >> g_app.age;
            cout << " New height : "; cin >> g_app.height;
            cout << " New weight : "; cin >> g_app.weight;
        }
        fout.write(reinterpret_cast<char*>(&g_app), sizeof(g_app));
    }
    fin.close(); fout.close();

    if (found)
    {
        remove("patients.dat");
        rename("patients_tmp.dat", "patients.dat");
        cout << "\n Record updated.\n";
    }
    else
    {
        remove("patients_tmp.dat");
        cout << "\n Record not found.\n";
    }
    platform_sleep(2);
}

void HeartAttack::postInquiry()
{
    clear_screen();
    print_banner();
    fout.open("inquiries.dat", ios::app | ios::binary);

    srand(static_cast<unsigned>(time(nullptr)));
    g_discussion.id = rand() % 90000 + 10000;

    cout << "\n Your Name   : "; safe_getline(g_discussion.name, sizeof(g_discussion.name));
    cout << " Inquiry     : "; safe_getline(g_discussion.inquiry, sizeof(g_discussion.inquiry));

    fout.write(reinterpret_cast<char*>(&g_discussion), sizeof(g_discussion));
    fout.close();

    cout << "\n Inquiry registered! Your ID: " << g_discussion.id << "\n";
    platform_sleep(2);
}

void HeartAttack::replyToInquiry()
{
    clear_screen();
    print_banner();

    fin.open("inquiries.dat", ios::in  | ios::binary);
    fout.open("replies.dat",  ios::app | ios::binary);

    cout << "\n─── Open Inquiries ─────────────────────────────────────────────────────\n";
    while (fin.read(reinterpret_cast<char*>(&g_discussion), sizeof(g_discussion)))
    {
        cout << " ID: "    << g_discussion.id
             << "  From: " << g_discussion.name
             << "\n  Q: "  << g_discussion.inquiry << "\n\n";
    }

    int targetId;
    fin.clear(); fin.seekg(0, ios::beg);
    cout << " Enter Inquiry ID to reply to: ";
    cin >> targetId;

    bool found = false;
    while (fin.read(reinterpret_cast<char*>(&g_discussion), sizeof(g_discussion)))
    {
        if (g_discussion.id == targetId) { found = true; break; }
    }

    if (found)
    {
        cout << " Your reply: ";
        safe_getline(g_discussion.reply, sizeof(g_discussion.reply));
        fout.write(reinterpret_cast<char*>(&g_discussion), sizeof(g_discussion));
        cout << "\n Reply saved.\n";
    }
    else
        cout << "\n Inquiry ID not found.\n";

    fin.close(); fout.close();
    platform_sleep(2);
}

void HeartAttack::viewInquiryReplies()
{
    clear_screen();
    print_banner();

    fin.open("inquiries.dat", ios::in | ios::binary);
    fout.open("replies.dat",  ios::in | ios::binary);

    cout << "\n─── Inquiries ──────────────────────────────────────────────────────────\n";
    while (fin.read(reinterpret_cast<char*>(&g_discussion), sizeof(g_discussion)))
    {
        cout << " ID: " << g_discussion.id << "  By: " << g_discussion.name
             << "\n  Q: " << g_discussion.inquiry << "\n\n";
    }
    cout << "\n─── Replies ────────────────────────────────────────────────────────────\n";
    while (fout.read(reinterpret_cast<char*>(&g_discussion), sizeof(g_discussion)))
    {
        cout << " ID: " << g_discussion.id
             << "\n  A: " << g_discussion.reply << "\n\n";
    }
    fin.close(); fout.close();

    cout << "\n Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void HeartAttack::aboutDeveloper()
{
    clear_screen();
    print_banner();
    cout << "\n  Developer : Michael Gyimah\n"
         << "  Project   : Heart Attack Diagnostic & Hospital Management System\n"
         << "  Language  : C++17\n"
         << "  Platform  : Cross-platform (Windows / Linux / macOS)\n\n"
         << "  This project demonstrates object-oriented design, file-based\n"
         << "  persistence, multi-role access control, and medical diagnostic\n"
         << "  logic based on real clinical biomarkers.\n\n"
         << DIVIDER;

    cout << " Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void HeartAttack::adminLogin()
{
    clear_screen();
    print_banner();

    fadmin.open("staff.dat", ios::in | ios::binary);
    ftemp.open("staff_tmp.dat", ios::out | ios::binary);
    int count = 0;
    while (fadmin.read(reinterpret_cast<char*>(&g_admin), sizeof(g_admin)))
    {
        ftemp.write(reinterpret_cast<char*>(&g_admin), sizeof(g_admin));
        ++count;
    }
    fadmin.close(); ftemp.close();

    if (count == 0)
    {
        cout << "\n No staff accounts exist. Please sign up first.\n";
        platform_sleep(2);
        g_admin.signUp();
        return;
    }

    char userId[30] = {0};
    char password[30] = {0};
    cout << "\n Staff User ID: "; cin >> userId;
    cout << " Password    : ";
    int i = 0;
    char ch;
    while (i < 29)
    {
        ch = get_char();
        if (ch == '\r' || ch == '\n') break;
        if (ch == '\b' || ch == 127) { if (i > 0) { cout << "\b \b"; --i; } continue; }
        cout << '*' << flush;
        password[i++] = ch;
    }
    password[i] = '\0';
    cout << '\n';

    fadmin.open("staff.dat", ios::in | ios::binary);
    bool ok = false;
    while (fadmin.read(reinterpret_cast<char*>(&g_admin), sizeof(g_admin)))
    {
        if (strcmp(userId, g_admin.staffUserId) == 0 &&
            strcmp(password, g_admin.staffPassword) == 0)
        { ok = true; break; }
    }
    fadmin.close();

    if (ok)
    {
        cout << "\n Login successful!\n";
        platform_sleep(1);
        adminMenu();
    }
    else
        cout << "\n Invalid credentials.\n";
}

void HeartAttack::adminMenu()
{
    bool back = false;
    while (!back)
    {
        clear_screen();
        print_banner();
        cout << "\n  ADMIN PORTAL\n" << DIVIDER
             << "  [1] List all patients\n"
             << "  [2] Search patient\n"
             << "  [3] Delete patient record\n"
             << "  [4] Update patient record\n"
             << "  [5] Count patients / staff\n"
             << "  [6] View staff records\n"
             << "  [7] Staff sign-up\n"
             << "  [8] Admin duties\n"
             << "  [9] Back\n"
             << "\n  Your choice: ";

        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1: displayAll(10, 20); break;
        case 2: searchRecord();     break;
        case 3: deleteRecord();     break;
        case 4: updateRecord();     break;
        case 5: g_admin.countRecords(); break;
        case 6:
        {
            clear_screen();
            print_banner();
            fadmin.open("staff.dat", ios::in | ios::binary);
            while (fadmin.read(reinterpret_cast<char*>(&g_admin), sizeof(g_admin)))
                cout << " Name: " << g_admin.staffName
                     << "  User ID: " << g_admin.staffUserId
                     << "  ID: " << g_admin.staffId << "\n";
            fadmin.close();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
        }
        case 7: g_admin.signUp();    break;
        case 8: g_admin.adminDuty(); break;
        case 9: back = true;         break;
        default: cout << "\n Invalid choice.\n"; platform_sleep(1);
        }
    }
}

void HeartAttack::clientSecuredLogin()
{
    clear_screen();
    print_banner();

    int targetId;
    long long int targetPhone;
    cout << "\n Your Patient ID : "; cin >> targetId;
    cout << " Your Phone No.  : "; cin >> targetPhone;

    // Simulate OTP
    srand(static_cast<unsigned>(time(nullptr)));
    int otp = rand() % 80000 + 10000;
    cout << "\n [Sending OTP...]\n";
    platform_sleep(3);
    cout << " Your OTP (valid 30s): " << otp << "\n";
    int entered;
    cout << " Enter OTP: "; cin >> entered;

    if (otp != entered)
    {
        cout << "\n OTP mismatch. Access denied.\n";
        platform_sleep(2);
        return;
    }

    fin.open("patients.dat", ios::in | ios::binary);
    bool found = false;
    while (fin.read(reinterpret_cast<char*>(&g_app), sizeof(g_app)))
    {
        if (g_app.id == targetId && g_app.phone == targetPhone)
        { found = true; break; }
    }
    fin.close();

    if (!found)
    {
        cout << "\n Invalid credentials.\n";
        platform_sleep(2);
        return;
    }

    bool back = false;
    while (!back)
    {
        clear_screen();
        print_banner();
        cout << "\n Welcome, " << g_app.name << "!\n" << DIVIDER
             << "  [1] Request record update\n"
             << "  [2] Change doctor\n"
             << "  [3] Check disease level\n"
             << "  [4] View medicines\n"
             << "  [5] Order medicines\n"
             << "  [6] File a complaint\n"
             << "  [7] View messages\n"
             << "  [8] Back\n"
             << "\n  Your choice: ";

        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1: g_client.updateMyRecord(); break;
        case 2: g_client.changeDoctor();   break;
        case 3: g_client.viewDiseaseLevel();break;
        case 4: g_client.checkMedicines(); break;
        case 5: g_client.buyMedicine();    break;
        case 6: g_client.registerComplaint();break;
        case 7: g_client.viewMessages();   break;
        case 8: back = true;               break;
        default: cout << "\n Invalid choice.\n"; platform_sleep(1);
        }
    }
}

// ─────────────────────────────────────────────────────────────────────────────
//  Administration
// ─────────────────────────────────────────────────────────────────────────────

void Administration::signUp()
{
    clear_screen();
    fadmin.open("staff.dat", ios::app | ios::binary);
    print_banner();

    cout << "\n Name      : "; cin >> staffName;
    cout << " User ID   : "; cin >> staffUserId;
    cout << " Password  : "; cin >> staffPassword;
    cout << " Phone     : "; cin >> staffPhone;
    cout << " Staff ID  : "; cin >> staffId;

    fadmin.write(reinterpret_cast<char*>(this), sizeof(*this));
    fadmin.close();
    cout << "\n Staff account created.\n";
    platform_sleep(2);
}

void Administration::countRecords()
{
    clear_screen();
    print_banner();
    int ch;
    cout << "\n Count: [1] Patients  [2] Staff\n Your choice: ";
    cin >> ch;

    int count = 0;
    if (ch == 1)
    {
        fin.open("patients.dat", ios::in | ios::binary);
        while (fin.read(reinterpret_cast<char*>(&g_app), sizeof(g_app))) ++count;
        fin.close();
    }
    else
    {
        fadmin.open("staff.dat", ios::in | ios::binary);
        while (fadmin.read(reinterpret_cast<char*>(&g_admin), sizeof(g_admin))) ++count;
        fadmin.close();
    }
    cout << "\n Total: " << count << "\n";
    platform_sleep(2);
}

void Administration::addMedicine()
{
    clear_screen();
    print_banner();
    fin.open("medicines.dat", ios::app | ios::binary);

    int n;
    cout << "\n How many medicines to add? "; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << " Medicine ID   : "; cin >> medicineId;
        cout << " Medicine Name : "; safe_getline(medicineName, sizeof(medicineName));
        cout << " Price ($)     : "; cin >> medicinePrice;
        fin.write(reinterpret_cast<char*>(this), sizeof(*this));
    }
    fin.close();
    cout << "\n Medicines added.\n";
    platform_sleep(2);
}

void Administration::viewComplaints()
{
    clear_screen();
    print_banner();
    fout.open("complaint_replies.dat", ios::app | ios::binary);
    fin.open("complaints.dat", ios::in | ios::binary);

    Client tmp;
    cout << "\n─── Complaints ─────────────────────────────────────────────────────────\n";
    while (fin.read(reinterpret_cast<char*>(&tmp), sizeof(tmp)))
        cout << " " << tmp.complaint << "\n\n";

    cout << " Write a reply: ";
    safe_getline(replyBuffer, sizeof(replyBuffer));
    fout.write(reinterpret_cast<char*>(this), sizeof(*this));
    fin.close(); fout.close();
}

void Administration::adminDuty()
{
    clear_screen();
    print_banner();
    bool back = false;
    while (!back)
    {
        cout << "\n  [1] Reply to inquiry\n"
             << "  [2] View complaints\n"
             << "  [3] Add medicines\n"
             << "  [4] Back\n"
             << "\n  Your choice: ";
        int ch; cin >> ch;
        switch (ch)
        {
        case 1: g_app.replyToInquiry(); break;
        case 2: viewComplaints();       break;
        case 3: addMedicine();          break;
        case 4: back = true;            break;
        default: cout << "\n Invalid choice.\n"; platform_sleep(1);
        }
    }
}

// ─────────────────────────────────────────────────────────────────────────────
//  Client
// ─────────────────────────────────────────────────────────────────────────────

void Client::updateMyRecord()
{
    clear_screen();
    ftemp.open("update_requests.dat", ios::app | ios::binary);
    cout << "\n Write your update request to admin:\n > ";
    safe_getline(updateRequest, sizeof(updateRequest));
    ftemp.write(reinterpret_cast<char*>(this), sizeof(*this));
    ftemp.close();
    cout << "\n Request submitted.\n";
    platform_sleep(2);
}

void Client::checkMedicines()
{
    clear_screen();
    fout.open("medicines.dat", ios::in | ios::binary);
    cout << "\n" << setw(12) << "Med ID" << setw(25) << "Name" << setw(12) << "Price\n"
         << DIVIDER;
    Administration med;
    while (fout.read(reinterpret_cast<char*>(&med), sizeof(med)))
        cout << setw(12) << med.medicineId << setw(25) << med.medicineName
             << "$" << setw(10) << med.medicinePrice << "\n";
    fout.close();
    cout << "\n Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void Client::buyMedicine()
{
    checkMedicines();
    float total = 0;
    char more = 'Y';
    while (more == 'Y' || more == 'y')
    {
        int mid, qty;
        cout << "\n Medicine ID to buy: "; cin >> mid;
        cout << " Quantity           : "; cin >> qty;

        fout.open("medicines.dat", ios::in | ios::binary);
        Administration med;
        while (fout.read(reinterpret_cast<char*>(&med), sizeof(med)))
            if (med.medicineId == mid) total += med.medicinePrice * qty;
        fout.close();

        cout << " Buy more? (Y/N): "; cin >> more;
    }
    cout << "\n─── Bill ───────────────────────────────────────────────────────────────\n"
         << " Total: $" << fixed << setprecision(2) << total << "\n" << DIVIDER;
    platform_sleep(3);
}

void Client::viewDiseaseLevel()
{
    clear_screen();
    fout.open("issues.dat", ios::in | ios::binary);
    int targetId;
    cout << "\n Enter your Patient ID: "; cin >> targetId;
    bool found = false;
    while (fout.read(reinterpret_cast<char*>(&g_issues), sizeof(g_issues)))
    {
        if (g_issues.id == targetId) { found = true; break; }
    }
    fout.close();
    if (found)
    {
        cout << "\n Troponin Level: " << g_issues.troponinLevel << " ng/mL\n";
        if      (g_issues.troponinLevel >= 0.40) cout << " Status: CRITICAL — probable acute MI\n";
        else if (g_issues.troponinLevel >= 0.04) cout << " Status: ELEVATED — cardiac injury possible\n";
        else                                      cout << " Status: NORMAL\n";
    }
    else
        cout << "\n No test data found.\n";
    platform_sleep(3);
}

void Client::registerComplaint()
{
    clear_screen();
    ftemp.open("complaints.dat", ios::app | ios::binary);
    cout << "\n Your complaint:\n > ";
    safe_getline(complaint, sizeof(complaint));
    ftemp.write(reinterpret_cast<char*>(this), sizeof(*this));
    ftemp.close();
    cout << "\n Complaint filed.\n";
    platform_sleep(2);
}

void Client::viewMessages()
{
    clear_screen();
    fin.open("complaint_replies.dat", ios::in | ios::binary);
    Administration rep;
    cout << "\n─── Admin Replies ──────────────────────────────────────────────────────\n";
    while (fin.read(reinterpret_cast<char*>(&rep), sizeof(rep)))
        cout << " " << rep.replyBuffer << "\n\n";
    fin.close();
    cout << "\n Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void Client::changeDoctor()
{
    cout << "\n Doctor-change feature is temporarily disabled by admin.\n";
    platform_sleep(3);
}

// ─────────────────────────────────────────────────────────────────────────────
//  Quick — walk-in rapid cardiac screening
// ─────────────────────────────────────────────────────────────────────────────

class Quick
{
public:
    Quick()
    {
        clear_screen();
        print_banner();

        char name[200]; int age; float weight, troponin, bodyTemp;

        cout << "\n Your name   : "; safe_getline(name, sizeof(name));
        cout << " Age         : "; cin >> age;
        cout << " Weight (kg) : "; cin >> weight;

        srand(static_cast<unsigned>(time(nullptr)));
        int gid = rand() % 961400 + 200000;
        cout << "\n Generated ID: " << gid << "\n";

        char hasSx;
        cout << "\n Do you have any of: chest pain, dizziness, fatigue, shortness of breath? (Y/N): ";
        cin >> hasSx;
        if (hasSx == 'Y' || hasSx == 'y')
            cout << " [Warning] These are key heart-attack symptoms. A full test is strongly advised.\n";

        cout << "\n [Simulating blood draw...]\n";
        platform_sleep(2);

        cout << " Troponin reading (AQT90) : "; cin >> troponin;
        cout << " Body temperature (°C)    : "; cin >> bodyTemp;

        cout << "\n [Analysing...]\n";
        platform_sleep(2);

        // Generate simulated CBC
        float hgb  = static_cast<float>(rand() % 8  + 10);
        float chol = static_cast<float>(rand() % 50 + 100);
        int   bgIdx= rand() % 8;

        clear_screen();
        print_banner();
        cout << "\n─── QUICK REPORT ───────────────────────────────────────────────────────\n"
             << " Name       : " << name       << "\n"
             << " Age        : " << age        << "\n"
             << " Weight     : " << weight     << " kg\n"
             << " Body Temp  : " << bodyTemp   << " °C\n"
             << " Blood Group: " << blood_group_name(bgIdx) << "\n"
             << " Haemoglobin: " << hgb  << " g/dL"
             << (hgb < 12 ? "  ← Low\n" : "\n")
             << " Cholesterol: " << chol << " mg/dL"
             << (chol > 160 ? "  ← High\n" : "\n");

        cout << "\n Troponin: " << troponin << " ng/mL  → ";
        if      (troponin < 0.04) cout << "Normal — no acute MI signs.\n";
        else if (troponin < 0.40) cout << "Elevated — possible cardiac injury. Book a full test.\n";
        else                      cout << "CRITICALLY HIGH — seek emergency care immediately.\n";

        cout << "\n * This is a preliminary screening only.\n"
             << "   Please see a physician for a full diagnosis.\n"
             << DIVIDER;

        // Medicine suggestion if elevated
        if (troponin >= 0.04)
        {
            cout << "\n Suggested medicines to discuss with your doctor:\n";
            if (troponin < 0.40)
                cout << "  • Apixaban  • Clopidogrel  • Benazepril  • Azilsartan  • Atenolol\n";
            else
                cout << "  • Aspirin  • Statins  • Beta-blockers  • ACE inhibitors  • Warfarin\n";
            cout << "\n Take prescribed doses only. Self-medication is dangerous.\n";
        }

        cout << "\n Press Enter to return to menu...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
};

// ─────────────────────────────────────────────────────────────────────────────
//  Diet — personalised dietary guidance
// ─────────────────────────────────────────────────────────────────────────────

class Diet
{
public:
    Diet()
    {
        clear_screen();
        print_banner();

        char name[200]; char hasDisease;
        cout << "\n Your name: "; safe_getline(name, sizeof(name));
        cout << " Do you have a diagnosed heart condition? (Y/N): ";
        cin >> hasDisease;

        clear_screen();
        print_banner();

        if (hasDisease == 'Y' || hasDisease == 'y')
        {
            cout << "\n─── Cardiac Diet Plan for " << name << " ──────────────────────────────────\n\n"
                 << " RECOMMENDED FOODS:\n"
                 << "  ✔  Fatty fish (salmon, mackerel) — omega-3 rich\n"
                 << "  ✔  Olive oil, avocado — healthy fats\n"
                 << "  ✔  Colourful fresh fruits and vegetables\n"
                 << "  ✔  Whole-grain cereals, oats, legumes\n"
                 << "  ✔  Low-fat dairy, eggs, lean poultry\n"
                 << "  ✔  Brown rice, sweet potatoes, spaghetti squash\n\n"
                 << " FOODS TO AVOID:\n"
                 << "  ✘  Trans fats (fried/processed food)\n"
                 << "  ✘  Excess salt (>1,500 mg/day)\n"
                 << "  ✘  Sugary drinks and refined carbohydrates\n"
                 << "  ✘  Red and processed meats\n\n"
                 << " TIP: Eat small meals every 3–4 hours to stabilise blood glucose.\n";
        }
        else
        {
            cout << "\n You can continue a balanced general diet, " << name << ".\n"
                 << " Aim for variety, moderation, and regular physical activity.\n";
        }

        cout << "\n Press Enter to return...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        g_app.mainMenu();
    }
};

// ─────────────────────────────────────────────────────────────────────────────
//  Wrappers for Quick and Diet (must appear after full class definitions)
// ─────────────────────────────────────────────────────────────────────────────

static void run_quick_checkup() { Quick(); }
static void run_diet_planner()  { Diet();  }

// ─────────────────────────────────────────────────────────────────────────────
//  main
// ─────────────────────────────────────────────────────────────────────────────

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int attempts = 0;
    bool ok = false;
    while (attempts < 3 && !ok)
    {
        ok = g_securedLogin.authenticate();
        if (!ok)
        {
            ++attempts;
            std::cout << "\n Attempt " << attempts << " of 3.\n";
            if (attempts < 3)
            {
                std::cout << " Retrying in 3 seconds...\n";
                platform_sleep(3);
            }
        }
    }

    if (!ok)
    {
        std::cout << "\n\n Access locked after 3 failed attempts. Exiting.\n";
        return 1;
    }

    g_app.mainMenu();
    return 0;
}
