#pragma once
#define rep(i, a, b) for (int i = (a); i < (int)(b); i++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; i >= (a); i--)
#define ALL(v) (v).begin(), (v).end()
#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())
#define SZ(v) (int)v.size()
#define MIN(v) *min_element(ALL(v))
#define MAX(v) *max_element(ALL(v))
#define LB(v, x) int(lower_bound(ALL(v), (x)) - (v).begin())
#define UB(v, x) int(upper_bound(ALL(v), (x)) - (v).begin())
#define YN(b) cout << ((b) ? "YES" : "NO") << "\n";
#define Yn(b) cout << ((b) ? "Yes" : "No") << "\n";
#define yn(b) cout << ((b) ? "yes" : "no") << "\n";