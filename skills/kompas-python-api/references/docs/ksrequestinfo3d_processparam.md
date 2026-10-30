# processParam - Параметры процесса

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [IRequestInfo - свойства ](ksrequestinfo3d_props.html) |  Scroll [ [ [ ](ksrequestinfo3d_prompt.html "К следующему разделу")](ksrequestinfo3d_props.html "На уровень выше")](ksrequestinfo3d_menuid.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrequestinfo3d.html)

Аналог данного свойства при использовании COM - методы [IRequestInfo::GetProcessParam](irequestinfo_getprocessparam.html) и [IRequestInfo::SetProcessParam](irequestinfo_setprocessparam.html).

Тип данных: указатель на интерфейс [IProcessParam](iprocessparam.html)

Синтаксис Automation:

processParam = iObject.ProcessParam | Получить свойство ([* ](1.html))  
---|---  
iObject.ProcessParam = processParam | Установить свойство ([* ](1.html))  
processParam = iObject.GetProcessParam() | Получить свойство ([**](2.html))  
iObject.SetProcessParam (processParam) | Установить свойство ([**](2.html))  
  
Примечания:

Если в интерфейсе параметров запроса к системе указатель на интерфейс параметров процесса не NULL, то при выполнении процесса UserGetPlacementAndEntity, элементы управления из IProcessParam попадут на Панель свойств процесса.

Подразделы:

(отсутствуют)
