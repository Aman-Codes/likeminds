// Name of program mainreturn.cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long

class Resource {
 public:
  string name;
  Resource(string resourceName) { name = resourceName; }
};

class Role {
 public:
  string name;
  Role(string roleName) { name = roleName; }
};

class User {
 public:
  string name;
  User(string userName) { name = userName; }
};

class Access {
 public:
  string name;
  Access(string access_name) { name = access_name; }
};

map<string, Resource*> resources;
map<string, User*> users;
map<string, Role*> roles;
map<string, Access*> access;
map<User*, Role*> user_role;
map<pair<Role*, Resource*>, Access*> access_alloted;
map<Resource*, vector<Access*>> resource_access;
map<User*, vector<Role*>> roles_allocated;

int32_t main() {
  string s;
  while (cin >> s) {
    cout << s << "\n";
    if (s == "addAccess") {
      string access_name;
      cin >> access_name;
      Access* a = new Access(access_name);
      access[access_name] = a;
    } else if (s == "addResource") {
      string resourceName;
      cin >> resourceName;
      Resource* r = new Resource(resourceName);
      resources[resourceName] = (r);
    } else if (s == "addAccessOnResource") {
      string accessName;
      string resourceName;
      cin >> accessName >> resourceName;
      Resource* r = resources[resourceName];
      Access* a = access[accessName];
      resource_access[r].push_back(a);
    } else if (s == "addRole") {
      string roleName;
      cin >> roleName;
      Role* u1 = new Role(roleName);
      roles[roleName] = u1;
    } else if (s == "addUser") {
      string userName;
      cin >> userName;
      User* u1 = new User(userName);
      users[userName] = u1;
    } else if (s == "addRoleToUser") {
      string roleName;
      string userName;
      cin >> roleName >> userName;
      Role* r = roles[roleName];
      User* u = users[userName];
      cout << "addRoleToUser " << roleName << " " << userName << "\n";
      roles_allocated[u].push_back(r);
      cout << roles_allocated[u].size() << "\n";
    } else if (s == "checkAccess") {
      string userName, resourceName, accessName;
      cin >> userName >> resourceName >> accessName;
      User* u = users[userName];
      Resource* r = resources[resourceName];
      Access* a = access[accessName];
      int n = (roles_allocated[u]).size();
      int m = (resource_access[r]).size();
      cout << "inside check admin\n" << n << " " << m << "\n";
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < m; ++k) {
          if (access_alloted[make_pair(roles_allocated[u][j], r)] == a) {
            cout << "YES\n";
          } else {
            cout << "NO\n";
          }
        }
      }
    } else if (s == "addAccessOnResourceToRole") {
      string roleName, resourceName, accessName;
      cin >> roleName >> resourceName >> accessName;
      Role* r1 = roles[roleName];
      Resource* r = resources[resourceName];
      Access* a = access[accessName];
      access_alloted[make_pair(r1, r)] = a;
    } else {
      cout << "none matched for " << s << "\n";
    }
  }
  return 0;
}

// addAccess READ addAccess WRITE addResource IMAGE1 addResource IMAGE2
// addAccessOnResource READ IMAGE1 addAccessOnResource WRITE IMAGE2 addRole
// ADMIN addAccessOnResourceToRole READ IMAGE1 ADMIN addAccessOnResourceToRole
// READ IMAGE2 ADMIN addUser ADMINUSER1 addRoleToUser ADMIN ADMINUSER1
// checkAccess ADMINUSER1 IMAGE1 WRITE