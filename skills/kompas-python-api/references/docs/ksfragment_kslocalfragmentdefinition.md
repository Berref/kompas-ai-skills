# ksLocalFragmentDefinition - Определить данные для последующей вставки локального фрагмента по ссылке

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Фрагмент (Интерфейс ksFragment) ](ksfragment.html) > [ksFragment - методы ](ksfragment_methods.html) |  Scroll [ [ [ ](ksfragment_ksreadfragment.html "К следующему разделу")](ksfragment_methods.html "На уровень выше")](ksfragment_ksinsertfragmentex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfragment.html)

Аналог данного метода при использовании API экспортных функций - [LocalFragmentDefinition](localfragmentdefinition.html).

Синтаксис Automation:

long ksLocalFragmentDefinition (LPCTSTR comment);

Входной параметр:

comment | \- имя вставки.  
---|---  
  
Возвращаемое значение:

указатель на определение фрагмента | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Вставка ссылки на фрагмент производится с помощью функции [ksInsertFragment](ksfragment_ksinsertfragment.html). Указатель на определение фрагмента возвращается при окончании описания - функцией [ksCloseLocalFragmentDefinition](ksfragment_kscloselocalfragmentdefinition.html).

Отдельного файла фрагмента нет; "тело" фрагмента хранится в документе.

Подразделы:

(отсутствуют)
