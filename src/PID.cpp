#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
	this->Kp = Kp_;
	this->Ki = Ki_;
	this->Kd = Kd_;

	p_error = i_error = d_error = 0.0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
	p_error = cte;
	d_error = cte - d_error ;
	i_error += cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
	double error =
			-p_error * Kp - d_error * Kd - i_error * Ki;
  return error;
}
