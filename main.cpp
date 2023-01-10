// Name of program mainreturn.cpp
#include <bits/stdc++.h>
using namespace std;

class Resource {
  public:
  string name;
  Resource(string resourceName) {
    name=resourceName;
  }
};

class Role {
  public:
    string name;
  Role(string roleName) {
    name=roleName;
  }
};

class User {
  public:
  string name;
  User(string userName) {
    name=userName;
  }
};

class Access {
  public: 
  string name;
  Access(string access_name) {
    name=access_name;
  }
};

map<string, Resource*> resources;
map<string, User*> users;
map<string, Role*> roles;
map<string, Access*> access;
map<User*, Role*>  user_role;
map<pair<Role*, Resource*>, Access*> access_alloted;
map<Resource*, vector<Access*>> resource_access;
map<User*, vector<Role*>> roles_allocated;

int main(int argc, char** argv)
{
	cout << "You have entered " << argc-1
		<< " arguments:" << "\n";

	for (int i = 1; i < argc; ++i) {
    if(argv[i]=="addAccess") {
      string access_name = argv[i+1];
      Access *a=new Access(access_name);
      access[access_name]=a;
      i++;
    } else if(argv[i]=="addResource") {
      string resourceName = argv[i+1];
      Resource *r = new Resource(resourceName);
      resources[resourceName] = (r);
      i++;
    } else if(argv[i]=="addAccessOnResource") {
      string accessName = argv[i+1];
      string resourceName = argv[i+2];
      Resource *r = resources[resourceName];
      Access *a = access[accessName];
      resource_access[r].push_back(a);
      i+=2;
    } else if(argv[i]=="addRole") {
      string roleName = argv[i+1];
      Role* u1 = new Role(roleName);
      roles[roleName]=u1;
      i++;
    }else if(argv[i]=="addUser") {
      string userName = argv[i+1];
      User* u1 = new User(userName);
      users[userName]=u1;
      i++;
    }else if(argv[i]=="addRoleToUser") {
      string userRole = argv[i+1];
      string userName = argv[i+2];
      User* u1 = new User(userName);
      users[userName]=u1;
      i++;
    } else if(argv[i]=="addRole") {
      string roleName = argv[i+1];
      Role* u1 = new Role(roleName);
      roles[roleName]=u1;
      i++;
    } else if(argv[i]=="addRoleToUser") {
      string roleName = argv[i+1];
      string userName = argv[i+2];
      Role* r = roles[roleName];
      User* u = users[userName];
      roles_allocated[u].push_back(a);
      i+=2;
    } else if(argv[i]=="checkAccess") {
      string userName = argv[i+1];
      string resourceName = argv[i+2];
      string accessName = argv[i+3];
      User* u = users[userName];
      Resource* r = resources[resourceName];
      Access* a = access[accessName];
      if(access_alloted[make_pair(u, r)]==a) {
        cout<<"YES\n";
      } else {
        cout<<"NO\n";
      }
      i+=2;
    } else if(argv[i]=="addAccessOnResourceToRole") {
      string roleName = argv[i+3];
      string resourceName = argv[i+2];
      string accessName = argv[i+1];
      Role* r1 = roles[roleName];
      Resource* r = resources[resourceName];
      Access* a = access[accessName];
      access_alloted[make_pair(r1, r)]=a;
      i+=2;
    }
  }
	return 0;
}


// addAccess READ addAccess WRITE addResource IMAGE1 addResource IMAGE2 addAccessOnResource READ IMAGE1 addAccessOnResource WRITE IMAGE2 addRole ADMIN addAccessOnResourceToRole READ IMAGE1 ADMIN addAccessOnResourceToRole READ IMAGE2 ADMIN addUser ADMINUSER1 addRoleToUser ADMIN ADMINUSER1 checkAccess ADMINUSER1 IMAGE1 WRITE