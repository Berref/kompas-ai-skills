# ksCloseLocalFragmentDefinition - Закончить определение локального фрагмента

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Фрагмент (Интерфейс ksFragment) ](ksfragment.html) > [ksFragment - методы ](ksfragment_methods.html) |  Scroll [ [ [ ](ksfragment_ksfragmentdefinition.html "К следующему разделу")](ksfragment_methods.html "На уровень выше")](ksfragment_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfragment.html)

Синтаксис Automation:

long ksCloseLocalFragmentDefinition();

Возвращаемое значение:

указатель на определение фрагмента | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Все объекты вида, вводимые между операторами [ksLocalFragmentDefinition](ksfragment_kslocalfragmentdefinition.html) и ksCloseLocalFragmentDefinition, принадлежат локальному фрагменту.

Возвращаемый указатель используется в функциях [ksInsertFragment](ksfragment_ksinsertfragment.html), [ksDeleteObj](ksdocument2d_ksdeleteobj.html).

Подразделы:

(отсутствуют)
