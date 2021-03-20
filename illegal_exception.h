//
// Created by Karim Alatrash on 2021-03-18.
//

#ifndef P2_ILLEGAL_EXCEPTION_H
#define P2_ILLEGAL_EXCEPTION_H


class illegal_exception {

public:
    const char * msg () const throw ()
    {
        return "illegal argument";
    }
};


#endif //P2_ILLEGAL_EXCEPTION_H
