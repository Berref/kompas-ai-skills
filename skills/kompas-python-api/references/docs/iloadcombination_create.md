# Create - Создать набор

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Сборка ](bc3308967.html) > [Интерфейс ILoadCombination ](iloadcombination.html) > [ILoadCombination - методы ](iloadcombination_methods.html) |  Scroll [ [ [ ](iloadcombination_delete.html "К следующему разделу")](iloadcombination_methods.html "На уровень выше")](iloadcombination_applyex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iloadcombination.html)

Синтаксис Automation:

long Create( LPCTSTR combinationName )

Синтаксис COM:

HRESULT Create([in] BSTR combinationName, [out, retval] long * result );

Входные параметры:

combinationName | \- имя набора.  
---|---  
  
Возвращаемое значение:

индекс набора в массиве наборов | \- в случае успеха,  
---|---  
-1 | \- в случае неудачи.  
  
Примечание:

1\. Метод позволяет создать пользовательский набор с заданным именем.

2\. В набор сохраняется текущее состояние дерева построения. То есть предварительно нужно отдельно пройтись по вставкам компонентов и выполнить команды Выгрузить или Загрузить компонент.

3\. Набор не становится автоматически текущим.

Подразделы:

(отсутствуют)
