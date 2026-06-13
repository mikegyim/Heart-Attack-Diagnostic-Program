# 🫀 Heart Attack Diagnostic & Hospital Management System

<div align="center">

![Language](https://img.shields.io/badge/Language-C%2B%2B17-blue?logo=cplusplus)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey?logo=cmake)
![Build](https://img.shields.io/badge/Build-CMake-green?logo=cmake)
![License](https://img.shields.io/badge/License-MIT-orange)
![Domain](https://img.shields.io/badge/Domain-Healthcare%20%2F%20Medical%20AI-red?logo=heart)

**A console-based, multi-role hospital management system for cardiac risk assessment — built in C++17.**

</div>

---

## 🧠 What It Does

This system simulates a real hospital diagnostic pipeline. A patient walks in, gets registered, books a doctor, undergoes clinical tests, and receives a risk-scored report — all from the terminal.

The diagnostic engine uses **three clinical biomarkers** used in real cardiology:

| Biomarker | Threshold | Clinical significance |
|-----------|-----------|----------------------|
| **Troponin (AQT90 FLEX)** | < 0.04 / 0.04–0.39 / ≥ 0.40 ng/mL | Normal / Possible injury / Acute MI |
| **Fasting Plasma Glucose (FPG)** | < 100 / 100–125 / ≥ 126 mg/dL | Normal / Pre-diabetic / Diabetic |
| **OGTT Glucose** | < 140 / 140–199 / ≥ 200 mg/dL | Normal / Pre-diabetic / Diabetic |

Diabetes and elevated cholesterol are leading comorbidities for **silent myocardial infarction** — the system accounts for this in its composite risk score.

---

## ✨ Features

### Patient Portal
- Patient registration (ID, name, age, sex, height, weight, phone)
- Doctor appointment booking with conflict checking
- Full diagnostic test (symptom questionnaire + lab inputs)
- OTP-authenticated patient login
- Order / track medicines
- File complaints & view admin responses
- View personal disease level and test results
- Request data updates

### Admin Portal
- Password-protected admin login with masked input
- Full CRUD on patient records
- Staff sign-up and management
- Medicine catalogue management
- View & reply to patient complaints and inquiries
- Patient and staff count statistics
- Admin duty routing (replies, complaints, medicines)

### Diagnostics
- **Pre-report** — patient summary before test
- **Diagnostic test** — structured clinical questionnaire + biomarker inputs
- **Final report** — composite risk score with severity classification:
  - 🟢 **Low risk** — maintain healthy lifestyle
  - 🟡 **Moderate risk** — see cardiologist within 2 weeks
  - 🟠 **High risk** — urgent medical attention needed
  - 🔴 **Critical** — seek emergency care immediately

### Quick Checkup (Walk-in)
Rapid screening for patients without prior registration: troponin + symptom check → instant preliminary report + medicine suggestions.

### Diet Planner
Personalised cardiac-friendly nutrition guidance based on diagnosed heart condition status.

---

## 🏗️ Architecture

```
┌────────────────────────────────────────────────────────────────┐
│                        main()                                  │
│                   System Authentication                        │
└────────────────────────┬───────────────────────────────────────┘
                         │
              ┌──────────▼──────────┐
              │  HeartAttack (app   │
              │  controller)        │
              │  mainMenu()         │
              └──┬────────┬─────────┘
                 │        │
    ┌────────────▼─┐    ┌─▼──────────────┐
    │  Client Menu │    │  Admin Menu     │
    │  ──────────  │    │  ────────────   │
    │  Register    │    │  CRUD patients  │
    │  Book appt   │    │  Staff mgmt     │
    │  Run test    │    │  Medicine cat.  │
    │  Report      │    │  Complaints     │
    │  Patient     │    │  Inquiries      │
    │  login       │    └────────────────┘
    └──────────────┘
         │
   ┌─────▼──────────────────────────────────────┐
   │           Data Layer (binary flat files)   │
   │  patients.dat  │  issues.dat               │
   │  appointments.dat  │  medicines.dat         │
   │  staff.dat  │  inquiries.dat               │
   │  complaints.dat  │  replies.dat            │
   └────────────────────────────────────────────┘
```

### Class Hierarchy

| Class | Responsibility |
|-------|---------------|
| `HeartAttack` | Main app controller — menus, patient CRUD, diagnostic flow |
| `Issues` | Stores per-patient clinical measurements |
| `Doctor` | Appointment records |
| `Administration` | Staff accounts, medicine catalogue, complaints |
| `Client` | Patient self-service (OTP login, orders, complaints) |
| `Bill` | Medicine billing |
| `SecuredLogin` | System-level auth with masked password input |
| `Quick` | Walk-in rapid cardiac screening |
| `Diet` | Dietary guidance module |
| `Discussion` | Inquiry/reply messaging |

---

## 🚀 Getting Started

### Prerequisites
- C++17-compatible compiler (GCC ≥ 9, Clang ≥ 9, MSVC 2019+)
- CMake ≥ 3.16

### Build with CMake (recommended)

```bash
git clone https://github.com/YOUR_USERNAME/heart-attack-diagnostic.git
cd heart-attack-diagnostic

cmake -S . -B build
cmake --build build

./build/heart_diagnostic      # Linux / macOS
build\Debug\heart_diagnostic  # Windows
```

### Build with g++ directly

```bash
g++ -std=c++17 -Wall -O2 -o heart_diagnostic heart_attack_diagnostic.cpp
./heart_diagnostic
```

### Default credentials

| Role | Login ID | Password |
|------|----------|----------|
| System | `software1` | `software2050` |

> **Note:** In a production deployment, credentials would be loaded from environment variables or a config file — never hardcoded.

---

## 💻 Demo

```
 WELCOME TO MICHAEL'S HEALTH CENTER
      Your Health, Our Priority!
─────────────────────────────────────────────────────────────────────────

  [1] Patient Portal
  [2] Admin Portal
  [3] Post an Inquiry
  [4] View Inquiry Replies
  [5] Quick Checkup
  [6] Diet Planner
  [7] Log Out
  [8] Exit

  Your choice:
```

**Diagnostic Report sample:**

```
─────────────────────────────────────────────────────────────────────────
 DIAGNOSTIC REPORT
─────────────────────────────────────────────────────────────────────────
 Patient : John Doe  |  Age: 55  |  Sex: M

 Chest discomfort  : High
 Dizziness         : Medium
 Fatigue           : High
─── Lab Results ───────────────────────────────────────────────────────
 Blood Group       : O+
 WBC Count         : 8500 cells/μL  → Normal
 Haemoglobin       : 14.2 g/dL  → Normal
 Cholesterol (LDL) : 175 mg/dL  → High
─── Glucose Tests ─────────────────────────────────────────────────────
 FPG  (112 mg/dL)  : Pre-diabetic
 OGTT (155 mg/dL)  : Pre-diabetic
─── Troponin (AQT90 FLEX) ─────────────────────────────────────────────
 Level: 0.45 ng/mL  → Critically high — acute MI highly probable

─────────────────────────────────────────────────────────────────────────
 RISK ASSESSMENT
─────────────────────────────────────────────────────────────────────────
 Result  : CRITICAL — Acute myocardial infarction highly likely.
 Advice  : SEEK EMERGENCY CARE IMMEDIATELY.
```

---

## 🔧 Technical Highlights

- **Cross-platform** — conditional compilation for Windows (`Sleep`, `_getch`, `cls`) vs POSIX (`sleep`, `termios`, ANSI escape codes)
- **Secure password input** — masked character-by-character input with backspace support on both Windows and POSIX
- **Binary flat-file persistence** — simple, dependency-free storage using C++ `fstream` with struct serialisation
- **Composite risk scoring** — combines troponin, glucose (FPG + OGTT), blood pressure, symptom severity, and family history into a single actionable score
- **OTP simulation** — client portal protected by a time-seeded 5-digit OTP
- **Modern C++17** — `reinterpret_cast` instead of C-style casts, `std::chrono` for sleep, `std::numeric_limits` for safe stream flushing
- **No external dependencies** — pure standard library

---

## 🗺️ Roadmap

- [ ] SQLite persistence (replace binary flat files)
- [ ] REST API layer (Crow or Pistache) for web-front integration
- [ ] AES-256 encryption for patient data at rest
- [ ] Machine-learning risk model (logistic regression on UCI Heart Disease dataset)
- [ ] Unit tests (Google Test)
- [ ] Docker container for one-command deployment
- [ ] GUI front-end (Qt or ImGui)

---

## 📚 Medical Reference

| Metric | Normal | At Risk | Critical |
|--------|--------|---------|----------|
| Troponin I | < 0.04 ng/mL | 0.04–0.39 ng/mL | ≥ 0.40 ng/mL |
| FPG (fasting glucose) | < 100 mg/dL | 100–125 mg/dL | ≥ 126 mg/dL |
| OGTT glucose | < 140 mg/dL | 140–199 mg/dL | ≥ 200 mg/dL |
| Blood pressure | 120/80 mmHg | 130–139/80–89 | ≥ 140/90 |
| LDL Cholesterol | < 100 mg/dL | 130–159 mg/dL | ≥ 160 mg/dL |

> Sources: American Heart Association guidelines, ACC/AHA 2023 Cardiac Biomarker Guidelines.

---

## ⚠️ Disclaimer

This software is a **portfolio demonstration project** and is **not a medical device**. It must not be used to make real clinical decisions. Always consult a licensed physician.

---

## 📄 License

MIT © Michael Gyimah

---

<div align="center">
  <i>Built with ❤️ and C++ — because performance matters in healthcare.</i>
</div>
