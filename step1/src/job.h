#ifndef __job_h__
#define __job_h__

class Job { //requirement a
public:
    virtual void Work() const = 0;
    virtual void TakeBreak() const = 0;
    virtual void Train() const = 0;
    virtual void GetSalary() const = 0;
    virtual ~Job() = default;
};

#endif
