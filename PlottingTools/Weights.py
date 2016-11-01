#helpful weight functions
def w_ll(fr,pr):
    return (-1.0)*( fr*fr*pr*pr ) / ((pr - fr )*(pr-fr))

def w_lt(fr,pr):
    return (pr*pr * (fr - fr*fr) ) / ( (pr -fr)*(pr-fr) );

def w_tt(fr,pr):
    return ( (fr) /( (pr -fr) *(pr-fr)) ) * ( fr*(1-pr)*(1-pr) - 2.0*pr*(1.0-pr)*(1.0-fr) ) 
