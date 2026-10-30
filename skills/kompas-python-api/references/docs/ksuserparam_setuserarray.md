# SetUserArray - Установить динамический массив ksDynamicArray типа LTVARIANT_ARR

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Параметры, определяемые пользователем(Интерфейс ksUserParam) ](ksuserparam.html) > [ksUserParam - методы ](ksuserparam_methods.html) |  Scroll [ [ [ ](ksdoublevalue.html "К следующему разделу")](ksuserparam_methods.html "На уровень выше")](ksuserparam_init.html "К предыдущему разделу")  
---|---  
  
[Интерфейс…](ksuserparam.html)

Синтаксис Automation:

BOOL SetUserArray (LPDISPATCH Array);

Входной параметр:

Array | \- указатель на интерфейс динамического массива [ksDynamicArray](ksdynamicarray.html)[ типа LTVARIANT_ARR.](ksdynamicarray.html)  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечание.

Для поддержки Unicode в интерфейс [ksLtVariant](ksltvariant.html) добавлено свойство [ksLtVariant::wstrVal](ksltvariant_wstrval.html). В динамический массив для строковых данных требуется добавлять однотипные типы строковых параметров. Они должны быть или все типа ltv_WStr, или все типа ltv_Str. Это критично при работе с атрибутами.

При получении пользовательских параметров требуется использовать тот же тип, что и при записи параметров. При работе с базой данных при создании отношения с помощью функции [ksDataBaseObject::ksRChar](ksdatabaseobject_ksrchar.html) требуется в массив добавить ksLtVariant с типом ltv_Str. При использовании функции [ksDataBaseObject::ksRCharW](ksdatabaseobject_ksrcharw.html) требуется добавить ksLtVariant с типом ltv_WStr.

Смотрите также: [ksLtVariant](ksltvariant.html)

Подразделы:

(отсутствуют)
