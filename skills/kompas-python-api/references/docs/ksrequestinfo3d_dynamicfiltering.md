# DynamicFiltering - Режим динамической фильтрации

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [IRequestInfo - свойства ](ksrequestinfo3d_props.html) |  Scroll [ [ [ ](ksrequestinfo3d_menuid.html "К следующему разделу")](ksrequestinfo3d_props.html "На уровень выше")](ksrequestinfo3d_cursorname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrequestinfo3d.html)

Аналог данного свойства при использовании COM - методы [IRequestInfo::GetDynamicFiltering](irequestinfo_getdynamicfiltering.html) и[ IRequestInfo::SetDynamicFiltering](irequestinfo_setdynamicfiltering.html).

Тип данных: BOOL

Значения свойства:

TRUE | \- режим динамической фильтрации включен.  
---|---  
  
Синтаксис Automation:

DynamicFiltering = iObject.DynamicFiltering | Получить свойство ([* ](1.html))  
---|---  
iObject.DynamicFiltering = DynamicFiltering | Установить свойство ([* ](1.html))  
DynamicFiltering = iObject.GetDynamicFiltering() | Получить свойство ([**](2.html))  
iObject.SetDynamicFiltering (DynamicFiltering) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

DynamicFiltering = iObject.GetDynamicFiltering() | Получить свойство ([* ](1.html))  
---|---  
iObject.SetDynamicFiltering (DynamicFiltering) | Получить свойство ([**](2.html))  
  
Примечания:

Свойство распространяется на работу процесса указания местоположения или объектов [ksDocument3D::UserGetPlacementAndEntity](ksdocument3d_usergetplacementandentity.html).

Перед запуском процесса определяются параметры запроса к системе - интерфейс ksRequestInfo3D, в котором можно определить функцию фильтрации.

Если свойство DynamicFiltering, определяющее режим динамической фильтрации, равно FALSE (умолчательный режим), то функция фильтрации вызывается только когда курсор проходит над объектом, чтобы библиотека могла сообщить системе подходит данный объект или нет. Если функция фильтрации возвращает TRUE, объект библиотеке подходит.

Если свойство DynamicFiltering равно TRUE, то функция фильтрации вызывается не только когда курсор проходит над объектом, но и когда объекта под курсором нет. В таком случае передается сигнал библиотеке, что объекта под курсором нет. Возвращаемое значение функции фильтрации игнорируется.

Если свойство включено, то метод фильтрации объектов, заданный функцией [ksRequestInfo3D::SetFilterCallBack](ksrequestinfo3d_setfiltercallback.html), будет вызываться динамически, не зависимо от того установлен курсор над объектом или нет.

Если свойство выключено, то метод будет вызываться, только если курсор находится над объектом.

Подразделы:

(отсутствуют)
