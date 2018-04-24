adv_graph.png : JQ_graph.py advection.txt
		python JQ_graph.py
advection.txt : advection
		./advection > advection.txt
advection: JQ_advection.cpp
		c++ JQ_advection.cpp -o advection
