#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iomanip>
using std::fixed;
using std::setprecision;

#include <iostream>
using std::cout;
using std::cin;
using std::istream;
using std::ostream;

#include <string>
using std::string;

class Time {
	friend void initialize(Time & t);
	friend void read(Time & t, istream & in);
	friend void print(const Time & t, ostream & out);
	friend double difference(const Time & t1, const Time & t2);

private:
	int hours;
	int minutes;
	int year;
	int month;
	int day;
};

void initialize(Time & t) {
	t.hours = t.minutes = 99;
}

void read(Time & t, istream & in) {
	in >> t.year;
	in.get();// reads -
	in >> t.month;
	in.get();// -
	in >> t.day;
	in.get();//-
	in >> t.hours;
	in.get(); // colon
	in >> t.minutes;
}

void print(const Time & t, ostream & out) {
	out << t.year << "-";
	out << fixed << setprecision(2) << t.month << "-";
	out << t.day << "-";
	out << t.hours << ':';
	if (t.minutes < 10)
		out << 0;
	out << t.minutes;
}

double difference(const Time & t1, const Time & t2) {

	double yearDiffrence = ((((t1.year - t2.year) * 360) * 24) *60);
	double monthDiffrence = ((((t1.month - t2.month) * 30) * 24)* 60);
	double dayDiffence = (((t1.day - t2.day) * 24) * 60);
	double hourDiffrence = (t1.hours - t2.hours) * 60;
	double minuteDiffrence = t1.minutes - t2.minutes;

	return (yearDiffrence + monthDiffrence + dayDiffence + hourDiffrence + minuteDiffrence) / 60.0;

}

int main() {

	cout << "Name of input file: ";
	string input_file_name;
	getline(cin, input_file_name);

	ifstream in(input_file_name);
	if (!in) {
		cout << "Could not open file.\n";
		return 1;
	}

	cout << "Name of output file: ";
	string output_file_name;
	getline(cin, output_file_name);

	ofstream out(output_file_name);
	if (!out) {
		cout << "Could not open output file.\n";
		return 1;
	}

	cout << "Name of pay rate file: ";
	string pay_file_name;
	getline(cin, pay_file_name);

	ifstream payIn(pay_file_name);
	if (!out) {
		cout << "Could not open pay rate file.\n";
		return 1;
	}

	int employee_number;
	while (in >> employee_number) {

		int startStops;
		Time start_time;
		Time stop_time;
		Time originalStart;
		double pay = 0;
		int payNumber;
		double pay_rate;

		payIn >> payNumber;
		payIn >> pay_rate;

		in >> startStops;

		for (int i = 1; i <= startStops; i++) {

			read(start_time, in);
			if (i == 1) {
				originalStart = start_time;
			}
			read(stop_time, in);

			pay = pay + (difference(stop_time, start_time) * pay_rate);
		}

		out << employee_number << ' ';
		print(originalStart, out);
		out << ' ';
		print(stop_time, out);
		out << " $" << fixed << setprecision(2) << pay << '\n';

	}

	return 0;
}
