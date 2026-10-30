# DeleteBranch - Удалить ответвление

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMark ](imark.html) > [IMark - свойства ](imark_props.html) > [Y - Координата точки привязки марки по Y ](imark_y.html) > [Интерфейс IMarkOnLeader ](imarkonleader.html) > [IMarkOnLeader - методы ](imarkonleader_methods.html) |  Scroll [ [ [ ](imarkinsideform.html "К следующему разделу")](imarkonleader_methods.html "На уровень выше")](imarkonleader_addbranchbypoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imarkonleader.html)

Синтаксис Automation:

BOOL DeleteBranch( long Index )

Синтаксис COM:

HRESULT DeleteBranch( [in]long Index, [out, retval] VARIANT_BOOL * Result );

Входные параметры:

index | \- индекс удаляемого ответвление.  
---|---  
  
Возвращаемое значение:

TRUE | \- ответвление удалено,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
