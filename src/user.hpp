#ifndef USER_HPP
#define USER_HPP

#include <cstring>
#include <string>

bool valid_username(const std::string &u);
bool valid_password(const std::string &p);
bool valid_name(const std::string &n);
bool valid_privilege(int g);

struct Index_user {
  char username[21] = {};
  int privilege = 0;
  int pos = 0;
  // Index_user() { std::memset(this, 0, sizeof(Index_user)); }
  bool operator<(const Index_user &rhs) const {
    int username_cmp = std::strcmp(username, rhs.username);
    if (username_cmp < 0) {
      return true;
    } else if (username_cmp > 0) {
      return false;
    }
    if (pos < rhs.pos) {
      return true;
    } else {
      return false;
    }
    return false;
  }
  bool operator>(const Index_user &rhs) const { return rhs < *this; }
  bool operator>=(const Index_user &rhs) const { return !(*this < rhs); }
  bool operator<=(const Index_user &rhs) const { return !(rhs < *this); }
  bool operator!=(const Index_user &rhs) const {
    return (*this < rhs) or (rhs < *this);
  }
};
struct User {
  char username[21] = {};
  char password[31] = {};
  char name[16] = {};
  char mail[31] = {};
  int privilege = 0;
  // User() { std::memset(this, 0, sizeof(User)); }
  bool operator<(const User &rhs) const {
    int username_cmp = std::strcmp(username, rhs.username);
    if (username_cmp < 0) {
      return true;
    } else if (username_cmp > 0) {
      return false;
    }
    int password_cmp = std::strcmp(password, rhs.password);
    if (password_cmp < 0) {
      return true;
    } else {
      return false;
    }
    return false;
  }
  bool operator>(const User &rhs) const { return rhs < *this; }
  bool operator>=(const User &rhs) const { return !(*this < rhs); }
  bool operator<=(const User &rhs) const { return !(rhs < *this); }
  bool operator!=(const User &rhs) const {
    return (*this < rhs) or (rhs < *this);
  }
};

bool add_user(const std::string &u, const std::string &p, const std::string &n,
              const std::string &m, int g, User &user);

bool login(const std::string &u, const std::string &p, User *user);

void query_profile(User *user);

bool modify_profile(User *user, const std::string &p, const std::string &n,
                    const std::string &m, int g);

#endif // USER_HPP
