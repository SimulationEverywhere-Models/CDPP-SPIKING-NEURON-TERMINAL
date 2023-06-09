%CDPlusPlus_Builder_Version_1.0.0

[top]
components : controller@Controller 
in : m_in m_inCount 
out : m_outFire m_outOff 
Link : m_in m_in@controller 
Link : m_inCount m_inCount@controller 
Link : m_outFire@controller m_outFire 
Link : m_outOff@controller m_outOff 

[controller] 
cycleTime : 00:00:00:001 
