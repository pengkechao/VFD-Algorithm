newAlgorithm: VFD algorithm designed by the authors£¬it is based on VF2 library. it changes the IsFeasiblePair() in vf2_state.cpp and the IsDead() in vf2_state.h. 
PreAlgorithm: VF2 algorithm offered by MIVIA Lab.
data/iso/rand(m2D, m3D, m4D): selected from ARG graph data and generated using generators from MIVIA Lab
data/iso/output: directory of results.
format of /data/iso/output/*.txt: nodes  edges matching_time state_counts  judge_time flag
where
matching_time: do not include the time spent reading graph data
state_counts: the number of states need to search during matching process
judege_time: time spent judging the next_node whether to be added into current state.
flag: 0 means the two graphs are isomorphic. 1 means the two graphs are not isomorphic

VFD spent less time than VF2 for random graphs in graph isomorphism.

NOTES:
the unit of time is ms.
when run the program, nead to make a directory "output" in directory of "data/iso/".then the results will be in data/iso/output
using the source code, please cite:
1.A large database of graphs and its use for bechmarking graph isomorphism algorithms
2.A Database of Graphs for Isomorphism and Sub-Graph isomorphism Benchmarking
3.A (sub)graph isomorphism algorithm for matching large graphs
4.An improved method of VF2 algorithm for directed graph isomorphism

there is any questions, please send email to me.(rhengzi@foxmail.com)

