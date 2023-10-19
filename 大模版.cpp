#include <bits/stdc++.h>

class _random {
#define ttp(x) template<typename x>
private:
    std::random_device _rd;
    std::mt19937 _rd32;
    std::mt19937_64 _rd64;
public:
    _random() { srand(_rd()); _rd32 = std::mt19937(_rd()); _rd64 = std::mt19937_64(_rd()); }
    ttp(_Tp) _Tp rd() { return rand() << 15 | rand(); }
    ttp(_Tp) _Tp rd(const _Tp r) { return rd<_Tp>() % r; }
    ttp(_Tp) _Tp rd(const _Tp l, const _Tp r) { return rd<_Tp>() % (r - l + 1) - l; }
    ttp(_Tp) _Tp rd32() { return _rd32(); }
    ttp(_Tp) _Tp rd32(const _Tp r) { return (rd32<_Tp>() % r + r) % r; }
    ttp(_Tp) _Tp rd32(const _Tp l, const _Tp r) { return rd32<_Tp>(r - l + 1) - l; }
    ttp(_Tp) _Tp rd64() { return _rd64(); }
    ttp(_Tp) _Tp rd64(const _Tp r) { return (rd64<_Tp>() % r + r) % r; }
    ttp(_Tp) _Tp rd64(const _Tp l, const _Tp r) { return rd64<_Tp>(r - l + 1) - l; }
} random;

class timer {
#define duration_tp std::chrono::system_clock::duration
#define return_tp double
#define get_clock std::chrono::system_clock::now().time_since_epoch()
private:
    struct node {
        bool isget; duration_tp sys;
        void _get() { isget = true, sys = get_clock; }
        void _reset() { isget = false; }
        friend duration_tp operator -(const node &a, const node &b) { return a.sys - b.sys; }
    } st, ed;
    duration_tp _duration() { if (!st.isget) throw "NOT START"; if (!ed.isget) throw "NOT STOP"; return ed - st; }
public:
    enum type { s, ms, us, ns };
    void start() { ed._reset(), st._get(); }
    bool stop() { if (!st.isget) return false; ed._get(); return true; }
    return_tp get(type tp) {
        try {
            return_tp now = _duration().count();
            switch (tp) {
                case ns: return now;
                case us: return now / 1000.0;
                case ms: return now / 1000000.0;
                case s: return now / 1000000000.0;
                default: return -1.0;
            }
        } catch (const char* msg) {
            std::cerr << msg << std::endl;
            return -1.0;
        }
    }
#undef duration_tp
#undef return_tp
#undef get_clock
};

// using namespace std;

signed main() {
    timer mn;
    mn.start();
    int a = 0;
    for (int i = 1; i <= random.rd32(100); ++i) a += random.rd32<int>(100);
    printf("%d\n", a);
    mn.stop();
    printf("%lf s\n", mn.get(timer::s));
    printf("%lf ms\n", mn.get(timer::ms));
    printf("%lf us\n", mn.get(timer::us));
    printf("%lf ns\n", mn.get(timer::ns));
    return 0;
}
