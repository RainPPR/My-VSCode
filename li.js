// ��ȡ UA
var ua = navigator.userAgent.toLowerCase();
// iOS �汾
var ver1 = ua.match(/cpu iphone os (.*?) like mac os/);
var ver2 = ua.match(/android (.*?);/);
// �Ƿ��� iOS
if (!ver1) {
    // �Ƿ��� Android
    if (!ver2)
        document.write("����iOS����Androidϵͳ�д�");
    else
        document.write("����ǰ��ϵͳ��Android");
}
else {
    document.write("����ǰ��iOSϵͳ�汾Ϊ��" + ver1[1].replace(/_/g, "."));
    if (ver1[1].replace(/_/g, ".") == "12.5.7")
        document.write("���ʺϴ˲��");
    else
        document.write("�����ʺϴ˲��");
}