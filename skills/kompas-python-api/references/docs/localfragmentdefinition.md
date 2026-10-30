# LocalFragmentDefinition - Начать определение локального фрагмента

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с фрагментами и библиотеками фрагментов ](cm1731223.html) > [Функции работы с фрагментами ](frags_fncts_common.html) > [Фрагменты ](frags_fncts.html) |  Scroll [ [ [ ](localfragmentdefinitionw.html "К следующему разделу")](frags_fncts.html "На уровень выше")](ksreadfragmenttogroupexw.html "К предыдущему разделу")  
---|---  
  
[Пример...](func_rab_s_frw_example.html)

Аналог данной функции при использовании Automation - метод [ksFragment::ksLocalFragmentDefinition](ksfragment_kslocalfragmentdefinition.html).

Синтаксис:

int LocalFragmentDefinition(char * comment);

Входной параметр:

comment | \- имя вставки.  
---|---  
  
Возвращаемое значение:

указатель на определение фрагмента | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Вставка ссылки на фрагмент производится с помощью функции [InsertFragment](insertfragment.html). 

2\. Все объекты вида, вводимые между функциями [LocalFragmentDefinition](localfragmentdefinition.html) и CloseLocalFragmentDefinition, принадлежат локальному фрагменту.

3\. При использовании Unicode следует использовать функцию [LocalFragmentDefinitionW](localfragmentdefinitionw.html).

Подразделы:

(отсутствуют)
