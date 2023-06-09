[top]
components : timer@Timer controller@Controller 
in : neuron_on neuron_off
out : neuron_out clk_control

Link : neuron_on m_inTurnOn@timer
%Link : m_inTurnOff m_inTurnOff@timer %this is excluded in the coupled model
Link : out_clk@timer clk_control
Link : out_count@timer m_inCount@controller 

Link : neuron_off m_in@controller 
%Link : m_inCount m_inCount@controller 
Link : m_outFire@controller neuron_out 
Link : m_outOff@controller m_inTurnOff@timer %internal link between Timer and Controller

[timer]
in : m_inTurnOn m_inTurnOff 
out : out_clk out_count
cycle : 00:00:00:001

[controller]
in : m_in m_inCount 
out : m_outFire m_outOff 
cycleTime : 00:00:00:001 