# Update - Обновить описание спецификации в соответствии с внесенными в настройки изменениями

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - методы ](ispecificationtuning_methods.html) |  Scroll [ [ [ ](ispecificationtuningsection.html "К следующему разделу")](ispecificationtuning_methods.html "На уровень выше")](ispecificationtuning_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Синтаксис Automation:

BOOL Update();

Синтаксис COM:

HRESULT Update ([out, retval] VARIANT_BOOL* pVal);

Возвращаемое значение:

TRUE | \- обновление прошло успешно,  
---|---  
FALSE | \- обновить настройки не удалось.  
  
Примечание:

Все изменения, сделанные в интерфейсах настроек спецификации, вступят в силу только после вызова этого метода.

Подразделы:

(отсутствуют)
