class Codec {
public:
    string serialize(TreeNode* root) {
        if(root==NULL){return "";}
        string str;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL)
            {
                str.append("#,");
            }
            else
            {
                str.append(to_string(curr->val)+',');
            }
           if(curr!=NULL)
           {
               q.push(curr->left);
               q.push(curr->right);
           }
        }
       return str; 
    }
    TreeNode* deserialize(string data) {
        if(data.size()==0){return NULL;}
        stringstream ss(data);
        string str;
        getline(ss,str,',');
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            getline(ss,str,',');
            if(str=="#")
            {
                curr->left=NULL;
            }
            else
            {
                TreeNode* leftNode = new TreeNode(stoi(str));
                curr->left = leftNode;
                q.push(leftNode);
            }
            
            getline(ss,str,',');
            if(str=="#")
            {
                curr->right = NULL;
            }
            else
            {
                TreeNode* rightNode = new TreeNode(stoi(str));
                curr->right = rightNode;
                q.push(rightNode);
            }
        }
      return root;  
    }
};