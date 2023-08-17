#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Patient {
public:
    string name;
    int age;
    string gender;
    string medicalHistory;

    Patient(string n, int a, string g, string mh) : name(n), age(a), gender(g), medicalHistory(mh) {}
};

class Doctor {
public:
    string name;
    string specialization;

    Doctor(string n, string s) : name(n), specialization(s) {}
};

class Appointment {
public:
    string patientName;
    string doctorName;
    time_t appointmentTime;

    Appointment(string pn, string dn, time_t at) : patientName(pn), doctorName(dn), appointmentTime(at) {}
};

class Hospital {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;

public:
    void addPatient(string name, int age, string gender, string medicalHistory) {
        patients.push_back(Patient(name, age, gender, medicalHistory));
    }

    void addDoctor(string name, string specialization) {
        doctors.push_back(Doctor(name, specialization));
    }

    void scheduleAppointment(string patientName, string doctorName, time_t appointmentTime) {
        appointments.push_back(Appointment(patientName, doctorName, appointmentTime));
    }

    void displayAppointments() {
        cout << "Scheduled Appointments:\n";
        for (const Appointment& appointment : appointments) {
            cout << "Patient: " << appointment.patientName << ", Doctor: " << appointment.doctorName
                 << ", Time: " << ctime(&appointment.appointmentTime);
        }
    }
};

int main() {
    Hospital hospital;

    hospital.addDoctor("Dr. Joe", "Cardiologist");
    hospital.addDoctor("Dr. Johnson", "Dentist");

    hospital.addPatient("Joshua", 27, "Male", "None");
    hospital.addPatient("Ama", 25, "Female", "Asthma");

    time_t appointmentTime1 = time(nullptr) + 24 * 3600;  // 24 hours from now
    hospital.scheduleAppointment("Joshua", "Dr. Joe", appointmentTime1);

    time_t appointmentTime2 = time(nullptr) + 48 * 3600;  // 48 hours from now
    hospital.scheduleAppointment("Ama", "Dr. Johnson", appointmentTime2);

    hospital.displayAppointments();

    return 0;
}
