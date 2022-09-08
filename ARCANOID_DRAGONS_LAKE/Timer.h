#pragma once
#include <chrono>

class Timer
{
public:
	Timer() { _isStarted = false; }
	Timer(double targetSeconds)
	{
		_targetSeconds = targetSeconds;
		_isStarted = false;
	}

	void Start()
	{
		_isStarted = true;
		start = std::chrono::system_clock::now();
	}

	void SetTime(double second) { _targetSeconds = second; }

	bool IsComplete()
	{
		if (!_isStarted) return false;

		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		
		if (elapsed_seconds.count() >= _targetSeconds)
		{
			_isStarted = false;
		}

		return elapsed_seconds.count() >= _targetSeconds;
	}

	bool IsStarted()
	{
		return _isStarted;
	}

private:
	bool _isStarted;
	float _targetSeconds;
	std::chrono::time_point<std::chrono::system_clock> start, end;
};