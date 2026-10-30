# LocalFragmentDefinitionW - Начать определение локального фрагмента (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с фрагментами и библиотеками фрагментов ](cm1731223.html) > [Функции работы с фрагментами ](frags_fncts_common.html) > [Фрагменты ](frags_fncts.html) |  Scroll [ [ [ ](writefragment.html "К следующему разделу")](frags_fncts.html "На уровень выше")](localfragmentdefinition.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksFragment::ksLocalFragmentDefinition](ksfragment_kslocalfragmentdefinition.html).

Синтаксис:

int LIB_FUNC LocalFragmentDefinitionW( LPWSTR comment);

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

3\. При использовании ANSI следует использовать функцию [LocalFragmentDefinition](localfragmentdefinition.html).

Подразделы:

(отсутствуют)
