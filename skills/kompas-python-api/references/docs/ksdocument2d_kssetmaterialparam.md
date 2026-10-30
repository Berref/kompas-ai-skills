# ksSetMaterialParam - Установить параметры материала в чертеже

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_kssetmixdlgmaterialparam.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_kssavetodxf.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksSetMaterialParam](kssetmaterialparam.html).

Синтаксис Automation:

long ksSetMaterialParam (LPDISPATCH material, double density);

Входные параметры:

material | \- наименование материала, указатель на интерфейс динамического массива [ksDynamicArray](ksdynamicarray.html) строк текста (TEXT_LINE_ARR),  
---|---  
density | \- плотность (г/куб.мм).  
  
Возвращаемое значение:

1 | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
