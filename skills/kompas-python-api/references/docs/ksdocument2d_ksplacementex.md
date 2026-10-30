# ksPlacementEx - Запрос к системе на получение координат точки и угла

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_kspointfrommtr.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_ksplacement.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [PlacementEx](placementex.html).

Синтаксис Automation:

long ksPlacementEx (LPDISPATCH info,

double* x,

double* y,

double* angle,

LPDISPATCH phantom,

LPDISPATCH processParam);

Входные параметры:

info | \- указатель на интерфейс параметров запроса к системе [ksRequestInfo](ksrequestinfo.html),  
---|---  
phantom | \- указатель на интерфейс фантома [ksPhantom](ksphantom.html),  
processParam | \- указатель на интерфейс параметров процесса [IProcessParam](iprocessparam.html).  
  
Выходные параметры:

x, y | \- возвращаемые координаты точки.  
---|---  
angle | \- возвращаемое значение угла.  
  
Возвращаемое значение:

-1 | \- если указана точка,  
---|---  
0 | \- отказ (Esc), идентификатор выбранной команды из командной строки или меню, определенный в файле ресурсов.  
  
Примечание:

Возможные варианты (команды) задаются в строке commands интерфейса [ksRequestInfo](ksrequestinfo.html) и разделяются восклицательными знаками или пробелами. Если вместо строки в качестве параметра передать идентификатор меню из файла ресурсов, то соответствующее меню будет выдано в окне приглашений. Если функция обратной связи ksRequestInfo не определена, то действие метода прекращается после первого шага.

Подразделы:

(отсутствуют)
