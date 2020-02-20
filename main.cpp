#include <iostream>
#include <vector>

int main() {
    /*We aren't using standard C I/0, or multi threading,
     * so it's significant speed up,
     * needed for test case 5a and 5b
     * otherwise they fail because of timeout without it
     */
    std::ios_base::sync_with_stdio(false);
    /*
     * Reading number of buildings. If there is 0 as input, we return 0
     */
    unsigned int buildNum;
    std::cin>>buildNum;
    if(buildNum==0){
        std::cout<<0<<std::endl;
        return 0;
    }
    /*
     * Rest of used variables. Width is useless, so we discard it;
     */
    std::vector<unsigned int> heightStack{};
    unsigned int discard;
    unsigned int posterAmount=0;
    unsigned int currHeight;
    for(unsigned int i=0;i<buildNum;i++){
        std::cin>>discard;
        std::cin>>currHeight;
        /*
         * If next building is lower than our right-most building
         * We search the stack, for the building with same height
         * If we find it, we can move to next building, because
         * there is a poster we can add
         */
        while(!heightStack.empty() && heightStack.back() > currHeight){
            heightStack.pop_back();
        }
        /*
         * If next building is higher OR next building is lowest one yet
         * We add to amount of posters and add it to our stack of buildings
         */
        if(heightStack.empty() || heightStack.back() < currHeight){
            posterAmount++;
            heightStack.push_back(currHeight);
        }
    }
    std::cout<<posterAmount<<std::endl;
    return 0;
}