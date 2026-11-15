class Solution {
public:
    vector<vector<int>>child;

    int fn(int idx, vector<int>& parent, vector<int>& op, vector<int>& score){
        if(child[idx].empty()){
            return score[idx];
        }
        int si = score[idx];
        
        vector<int>cs; /// child score
        int mini = INT_MAX;
        for(int x : child[idx]){
            int ci = fn(x,parent,op,score);
            cs.push_back(ci);
            si += ci;
            mini = min(mini,ci);
        }
        // atleast 1 child node to hoga hi bcz non leaf
        

        if(op[idx] == 1){
            // must choose minimum ko si se hatayenge 
            return si -mini;
        
        }
        else{
            if(mini < 0){
                return si-mini;
            }
            else{
                return si;
            }
        }



        // I will go to each children of nodei
    }
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        // parent[i] -> parent of node i
        // op[i] -> operation allowed at node i
        // score[i] -> represent its score

        // non leaf node 
        // op[i] = 0 -> choose atmost one child of node i -> set score of child subtree = 0
        // op[i] = 1 -> exactly one child of node i -> set score  = 0

        // exactly ones
        // maximum possible sum of scores after performing operations 
        // which node has less children => jiska sum of children node kam ho usi ko select karenge 
        int n= parent.size();

        child.assign(n,{});
        for(int i = 1; i <n; i++){
            child[parent[i]].push_back(i);
        }
        return fn(0,parent, op, score);

        
        
    }
};