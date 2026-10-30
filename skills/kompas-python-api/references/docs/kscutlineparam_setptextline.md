# SetpTextline - Установить указатель на интерфейс динамического массива компонент текста ksDynamicArray типа TEXT_ITEM_ARR

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Линия разреза/сечения (Интерфейс ksCutLineParam) ](kscutlineparam.html) > [ksCutLineParam - методы ](kscutlineparam_methods.html) |  Scroll [ [ [ ](ch1724533.html "К следующему разделу")](kscutlineparam_methods.html "На уровень выше")](kscutlineparam_setpmathpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutlineparam.html)

Синтаксис Automation:

BOOL SetpTextline (LPDISPATCH pTextline);

Входной параметр:

pTextline | \- указатель на интерфейс динамического массива [ksDynamicArray](ksdynamicarray.html) компонент текста типа TEXT_ITEM_ARR.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечание:

Массив используется при [ksCutLineParam::type](kscutlineparam_type.html) = 1 (т.е. при способе задания надписи на линии).

Смотрите также: [TextItemParam](structtextitemparam.html)

Подразделы:

(отсутствуют)
