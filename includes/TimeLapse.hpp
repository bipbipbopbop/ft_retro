#ifndef TIMELAPSE_HPP
# define TIMELAPSE_HPP

// Number of second we want to wait per lapse
#define TIME_LAPSE	0.1

class TimeLapse
{
public:
	TimeLapse();
	TimeLapse(TimeLapse const &src);
	~TimeLapse();

	TimeLapse  &operator=(TimeLapse const &rhs);

	void		start();
	void		update();
	bool		checkTime(double seconds);
	bool		checkTotalTime(double seconds) const;
private:
	double		_getTime() const;

	double		_elapsedTime;
	double		_totalTime;
	double		_lastTime;
};

#endif // TIMELAPSE_HPP