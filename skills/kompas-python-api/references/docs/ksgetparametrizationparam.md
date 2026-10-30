# ksGetParametrizationParam - Получить интерфейс параметров параметризации объектов

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](ksgetsnapinfo.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](ksgetorthomode.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::GetParamStruct](kompasobject_getparamstruct.html). В метод необходимо передать константу ko_ParametrizationParam.

Синтаксис:

IParametrizationParam * ksGetParametrizationParam();

Возвращаемое значение:

Указатель на интерфейс параметров параметризации объектов [IParametrizationParam](ksparametrizationparam.html) | \- в случае успешного завершения,  
---|---  
NULL | \- в случае неудачи.  
  
Примечание:

Данная функция используется совместно с ksParametrizeObjects. Объявление интерфейса IParametrizationParam дано в библиотеке типов kAPI2D5COM.tlb.

Подразделы:

(отсутствуют)
