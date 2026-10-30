////////////////////////////////////////////////////////////////////////////////
//
// gayka.h - Конструкторский элемент на Borland C - гайка 
//
////////////////////////////////////////////////////////////////////////////////
#ifndef __GAYKA_H
#define __GAYKA_H

#ifndef __BASE_H
#include "base.h"
#endif

//-------------------------------------------------------------------------------
// Указатели на отношения к БД
// ---
struct SimpleBase 
{
  reference bg;              // Указатель базы
  reference rg1, rg2, rg3;   // Указатели на 2 отношения
  SimpleBase() : bg(0), rg1(0), rg2(0), rg3(0) {};
};


//-------------------------------------------------------------------------------
// Параметры гайки
// ---
struct GaykaTMP
{
  float dr;
  float p1;
  float p2;
  float s;
  float D;
  float da;
  float h;
  float d2;
  float m;
  float s1;
  float D1;
  float m1;
};


//-------------------------------------------------------------------------------
// Параметры гайки
// ---
struct GAYKA5915
{
  float          dr;
  float          s;
  float          D;
  float          da;
  float          h;
  float          d2;
  float          p;
  unsigned short f;           // Битовые маски настройки
  short          klass;       // Класс точности
  unsigned short gost;        // Номер ГОСТа
  float          hatchAng;
  float          hatchShag;
  byte           ver;         // Версия макро
  float          massa;
  byte           indexMassa;  // 0-металл 1- алюмин сплав 2-латунь
  unsigned short f1;          // Битовые маски дополнительные
};


////////////////////////////////////////////////////////////////////////////////
//
// Класс гайки
//
////////////////////////////////////////////////////////////////////////////////
class Gayka5915 : public CPar
{
  public :
    GAYKA5915 tmp;
    SimpleBase base;

  public :
    Gayka5915( unsigned short gost_ );
    Gayka5915( const Gayka5915  & other );
    void  Assign( const Gayka5915  & other );

    virtual void        GetGroup( reference &gr ); // Геометрия гайки
    virtual int         ChoiceMenuId();            // Выбор меню
    virtual void        SetParam();                // Установка параметров
    virtual void        SetHatchAngl();            // Изменение угла штриховки
    virtual void        SetHatchShag();            // Изменение шага штриховки
    virtual int         MacroElementParam();       // Параметры макро объекта
    virtual reference   EditSpcObj( reference *spcObj, reference geom ); // Редактирование объекта спецификации

// HOT_POINTS ##################################################################
            // Работа с Hot точками
            BOOL        GetHotPoints( HotPointDescription* point,  int index );
            int         SetHotPoint ( HotPointDescription* point,  int index );
            BOOL        GetCursorText( int index, char** text );
            int         GetMenu();
            BOOL        ExecuteCommand( int id );                // Выполнение команды
            BOOL        EditComplete( int index, BOOL success ); // Редактирование и вставка объекта спецификации, если он был создан
            BOOL        ChangeHotPointParam( double d );
// HOT_POINTS ##################################################################

    virtual int         Size() { return CPar::Size() + sizeof(tmp); } // Размер данных
    virtual bool        IsSpcObjCreate() { return SPCOBJ_CREATE;}     // Функция проверки подключения атрибутов или нет

            // Отрисовка геометрии гайки
            void        gayka_sverhu();
            void        gayka_p_k( int j );
  public:
    static  reference   StaticEditSpcObj ( bool flagMode, GAYKA5915 &tmp, reference */*spcObj*/, reference/*geom*/, uint16 );
            int         ChoiceBMP();              // Выбор слайда
            void        CloseGaykaBase();         // Закрыть базу данных
            bool        OpenGaykaBase();          // Открыть базу данных
            bool        ReadGaykaBase( float d ); // Читать параметры гайки по диаметру
};


//-------------------------------------------------------------------------------
// Вспомогательные функции
// ---
// Отрисовка геометрии гайки
extern void gayka_k_side  ( float ls, float s, float D, float d2, float H, int j, int j2 );
// Отрисовка геометрии гайки
extern void gayka_k_y     ( float ls, GAYKA5915 *tmp, int j );
// Отрисовка геометрии гайки
extern void gayka_k       ( float ls, float l, float d1, float s, float D, float l1, float H, short j, int j1, float d2, int j2 );
#endif
