# GetInterface - Получить вспомогательный интерфейс

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument1 ](ikompasdocument1.html) > [IKompasDocument1 - методы ](ikompasdocument1_methods.html) |  Scroll [ [ [ ](ikompasdocument1_getobjectid.html "К следующему разделу")](ikompasdocument1_methods.html "На уровень выше")](ikompasdocument1_getexternalfilesnamesex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument1.html)

Синтаксис Automation:

LPDISPATCH GetInterface( long Type );

Синтаксис COM:

HRESULT GetInterface( KompasAPIObjectTypeEnum Type,

IKompasAPIObject ** Result );

Входные параметры:

Type | \- тип интерфейса из перечисления [KompasAPIObjectTypeEnum](kompasapiobjecttypeenum.html).  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс [IKompasAPIObject](ikompasapiobject.html).  
---|---  
  
Примечание:

Метод позволяет получить вспомогательный интерфейс.

В зависимости от значения параметра Type возвращается указатель на интерфейс:

•в 2D документе:

•ksObjectCopyObjectParam - параметры копирования [ICopyObjectParam](icopyobjectparam.html)

•ksObjectCurveCopyObjectParam - параметры копирования по кривой [ICurveCopyObjectParam](icurvecopyobjectparam.html)

•ksObjectCircleCopyObjectParam - параметры копирования по окружности [ICircleCopyObjectParam](icirclecopyobjectparam.html)

•ksObjectCircularCopyObjectParam - параметры копирования по концентрической сетке [ICircularCopyObjectParam](icircularcopyobjectparam.html)

•ksObjectMeshCopyObjectParam - параметры копирования по сетке [IMeshCopyObjectParam](imeshcopyobjectparam.html)

•ksObjectFindObjectParameters - интерфейс расширенного поиска объектов [IFindObjectParameters](ifindobjectparameters.html)

•в 3D документе:

•case ksObjectReportProcess - интерфейс для управления процессом Создать отчет[IReportProcess](ireportprocess.html)

•ksObjectSaveAsDetailParam - Параметры преобразования в модель [ISaveAsDetailParam](isaveasdetailparam.html)

•ksObjectFindObject3DParameters - Параметры поиска объектов 3D [IFindObject3DParameters](ifindobject3dparameters.html)

•В 2D, 3D и документе - спецификации

•ksSpecificationObjectCreateParam - Расширенные параметры создания объекта спецификации [ISpecificationObjectCreateParam](ispecificationobjectcreateparam.html)

Подразделы:

(отсутствуют)
