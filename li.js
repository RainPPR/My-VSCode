// 获取 UA
var ua = navigator.userAgent.toLowerCase();
// iOS 版本
var ver1 = ua.match(/cpu iphone os (.*?) like mac os/);
var ver2 = ua.match(/android (.*?);/);
// 是否是 iOS
if (!ver1) {
    // 是否是 Android
    if (!ver2)
        document.write("请在iOS或者Android系统中打开");
    else
        document.write("您当前的系统是Android");
}
else {
    document.write("您当前的iOS系统版本为：" + ver1[1].replace(/_/g, "."));
    if (ver1[1].replace(/_/g, ".") == "12.5.7")
        document.write("，适合此插件");
    else
        document.write("，不适合此插件");
}