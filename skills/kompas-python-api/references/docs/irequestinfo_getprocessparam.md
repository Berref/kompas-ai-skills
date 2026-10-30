# GetProcessParam - Получить указатель на интерфейс параметров процесса

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [IRequestInfo - методы ](ksrequestinfo3d_methods.html) |  Scroll [ [ [ ](irequestinfo_getprompt.html "К следующему разделу")](ksrequestinfo3d_methods.html "На уровень выше")](ksrequestinfo3d_getplacement.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrequestinfo3d.html)

Аналог данного метода при использовании Automation - свойство [ksRequestInfo3D::processParam](ksrequestinfo3d_processparam.html).

Синтаксис COM:

LPUNKNOWN GetProcessParam();

Возвращаемое значение:

| \- Указатель на интерфейс [IProcessParam](iprocessparam.html).  
---|---  
  
Примечания:

Если в интерфейсе параметров запроса к системе указатель на интерфейс параметров процесса не NULL, то при выполнении процесса UserGetPlacementAndEntity элементы управления из IProcessParam попадут на Панель свойств процесса.

Подразделы:

(отсутствуют)
