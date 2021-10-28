#pragma once
namespace interval {
	class Interval
	{
	private:
		double inf;
		double sup;
	public:
		Interval(double a = 0, double b = 0); // constructeur
		double min() const;// min de l'interval
		double max() const;//max de l'interval
		bool operator[](Interval&) const; // test si un interval incus dans l'autre
		bool operator[](double x) const; // test si un double appartient à la c'interval
		Interval& operator+(Interval& a) const;// union
		Interval& operator&&(Interval& a) const;//intersectIon

	};
}
