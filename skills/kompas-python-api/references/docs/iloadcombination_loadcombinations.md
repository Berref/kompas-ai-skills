# LoadCombinations - Массив наборов

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Сборка ](bc3308967.html) > [Интерфейс ILoadCombination ](iloadcombination.html) > [ILoadCombination - свойства ](iloadcombination_props.html) |  Scroll [ [ [ ](iloadcombination_protectedflags.html "К следующему разделу")](iloadcombination_props.html "На уровень выше")](iloadcombination_currentindex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iloadcombination.html)

Тип данных: VARIANT - массив наборов в виде массива SAFEARRAY BSTR - (VT_ARRAY | VT_BSTR)

Синтаксис Automation:

LoadCombinations = iObject.LoadCombinations | Получить свойство ([* ](1.html))  
---|---  
LoadCombinations = iObject.GetLoadCombinations() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_LoadCombinations ( &LoadCombinations) | Получить свойство ([* ](1.html))  
---|---  
  
Примечание:

1\. Свойство позволяет получить массив наборов документа.

2\. У сборки 3D есть три умолчательных набора, индексы которых соответствуют перечислению [ksLoadStateEnum.](ksloadstateenum.html):

Полная | 0 | \- полная загрузка,  
---|---|---  
Пустая | 1 | \- все компоненты не загружены,  
Упрощенная | 2 | \- все компоненты загружены частично.  
  
Кроме этого могут быть еще и пользовательские наборы.

Подразделы:

(отсутствуют)
