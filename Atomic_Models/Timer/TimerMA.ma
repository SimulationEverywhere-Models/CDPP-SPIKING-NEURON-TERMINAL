[top]
components : timer@Timer
in : m_inTurnOn m_inTurnOff 
out : out_clk out_count
Link : m_inTurnOn m_inTurnOn@timer
Link : m_inTurnOff m_inTurnOff@timer
Link : out_clk@timer out_clk
Link : out_count@timer out_count

[timer]
cycle : 00:00:00:001
