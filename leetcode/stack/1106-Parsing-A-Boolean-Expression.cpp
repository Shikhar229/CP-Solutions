class Solution {
public:

    bool f(string s,int &i){
        if(s[i] == 'f'){
            i++;
            
            return false;
        }
        if(s[i] == 't'){
            i++;
            
            return true;
        }


        char op = s[i];
        i+= 2;

        bool result;
        if(op == '&'){
            result = true;
            while(s[i] != ')'){
                if(s[i]==','){
                    i++;
                    continue;
                }
                else{

                    bool a = f(s,i);
                    result = result && a;
                }
                
            }
        }
        else if(op== '|'){
            result = false;
            while(s[i] != ')'){
                
                if(s[i] == ','){
                    i++;
                    continue;
                    
                }
                else{

                    bool a = f(s,i);
                    result = result || a;
                }
                
            }

        }
        else{
            result = !f(s,i);

        }
        i++;
        return result;

    
        
    }
    bool parseBoolExpr(string expression) {
        int i = 0;
        return  f(expression, i);
        



        
    }

};