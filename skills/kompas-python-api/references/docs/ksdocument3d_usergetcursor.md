# UserGetCursor - Запустить процесс указания местоположения точки

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_usergetplacementandentity.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_updatedocumentparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

BOOL UserGetCursor (BSTR prompt, double * x, double * y, double * z);

Синтаксис COM:

BOOL UserGetCursor (LPOLESTR prompt, double * x, double * y, double * z);

Входные параметры:

promt | \- строка подсказки для пользователя.  
---|---  
  
Выходные параметры:

x | \- координата x точки, указанной пользователем,  
---|---  
y | \- координата y точки, указанной пользователем,  
z | \- координата z точки, указанной пользователем.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения (пользователь указал точку).  
---|---  
  
Подразделы:

(отсутствуют)
