# Пример создания библиотеки типа AddIn

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа Addin ](cr90777.html) |  Scroll [ [ [ ](cr95008.html "К следующему разделу")](cr90777.html "На уровень выше")](simple_sample_addin.html "К предыдущему разделу")  
---|---  
  
1\. #define ADDINS_PATH "HKEY_CURRENT_USER\Software\ASCON\KOMPAS-3D\AddIns\Моя библиотека"

STDAPI DllRegisterServer()

{

HRESULT hr = NOERROR;

TCHAR szModulePath[MAX_PATH];

GetModuleFileName( theApp.m_hInstance, szModulePath,

sizeof(szModulePath)/sizeof(TCHAR) );

CString strPath( ADDINS_PATH );

HKEY hKey;

DWORD dwDisposition;

if ( RegCreateKeyEx(HKEY_CURRENT_USER,

strPath, 0L, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL,

&hKey, &dwDisposition) != ERROR_SUCCESS )

{

hr = E_UNEXPECTED;

}

else

{

hr = RegSetValueEx( hKey, "Path", 0L, REG_SZ,

(CONST BYTE*)szModulePath, strlen(szModulePath) );

DWORD dwVal = 1;

hr = RegSetValueEx( hKey, "AutoConnect", 0L, REG_DWORD,

(CONST BYTE*)&dwVal, sizeof(DWORD) );

}

return hr;

}

STDAPI DllUnregisterServer()

{

HRESULT hr = NOERROR;

if ( RegDeleteKey(HKEY_CURRENT_USER, ADDINS_PATH) != ERROR_SUCCESS ) {

hr = E_UNEXPECTED;

}

return hr;

}

2\. Файлом типа reg

Пример:

Файл реестра "MyLibrary.reg"

REGEDIT4

[HKEY_CURRENT_USER\Software\ASCON\KOMPAS-3D\AddIns\Моя библиотека]

"ProgID"="MyLibrary.class1"

"Path"="c:\\\MyLibrary.rtw"

"AutoConnect"=dword:00000001

Содержимое реестра после регистрации файла "MyLibrary.reg"

HKEY_CURRENT_USER

Software

ASCON

KOMPAS-3D

AddIns

Моя библиотека

ProgID MyLibrary.class1

Path c:\\\MyLibrary.rtw

AutoConnect 1

Подразделы:

(отсутствуют)
