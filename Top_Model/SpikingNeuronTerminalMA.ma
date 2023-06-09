[top]
components : Transformer Neuron
in : in_1 in_2
out : terminal_output control_output

Link : in_1 in_1@Transformer
Link : in_2 in_2@Transformer
Link : out_1@Transformer neuron_on@Neuron
Link : out_2@Transformer neuron_off@Neuron
Link : neuron_out@Neuron terminal_output
Link : clk_control@Neuron control_output

[Transformer]
components : amp_1@Amp_1 amp_2@Amp_2
in : in_1  in_2
out : out_1 out_2
Link : in_1 in_1@amp_1
Link : out_1@amp_1 out_1
Link : in_2 in_2@amp_2
Link : out_2@amp_2 out_2
[amp_1]
cycle : 00:00:00:000
[amp_2]
cycle : 00:00:00:000

[Neuron]
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