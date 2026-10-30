# ReadString - Ввод строки

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IApplicationDialogs ](iapplicationdialogs.html) > [IApplicationDialogs - методы ](iapplicationdialogs_methods.html) |  Scroll [ [ [ ](iapplicationdialogs_savefile.html "К следующему разделу")](iapplicationdialogs_methods.html "На уровень выше")](iapplicationdialogs_readint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationdialogs.html)

Синтаксис Automation:

BOOL ReadString( OLE_HANDLE HWnd, BSTR Caption, long MaxLength, BSTR * Value );

Синтаксис COM:

HRESULT ReadString( OLE_HANDLE HWnd, BSTR Caption, long MaxLength, BSTR * Value, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

HWnd | \- дескриптор окна владельца,  
---|---  
Caption | \- заголовок,  
MaxLength | \- максимальная длина.  
  
Входной и выходной параметр:

Value | \- строка результат ввода.  
---|---  
  
Версия Компас v23

Подразделы:

(отсутствуют)
