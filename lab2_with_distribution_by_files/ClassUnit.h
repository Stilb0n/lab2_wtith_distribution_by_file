#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include<vector>
#include"unit.h"
#include <memory>




class IClassUnit : public Unit {
public:    enum AccessModifier // Здесь определены всевозможные спецификаторы доступа
    {
        PUBLIC,                     // C# C++ Java
        PROTECTED,             // C# C++ Java
        PRIVATE,               // C# C++ Java
        INTERNAL,              // C#
        PROTECTED_INTERNAL,    // C#
        PRIVATE_PROTECTED,     // C#
    };
  static    const std::vector< std::string > ACCESS_MODIFIERS;   // инициализирован вне класса
    virtual void add(const std::shared_ptr< Unit >& unit, Flags flags ) = 0;
  protected:
  std::string m_name; // имя класса
  using Fields = std::vector<std::shared_ptr<Unit>>;  // вектор член-функций/член-данных.
  std::vector<Fields> m_fields;   // вектор, характеризующий модификаторы достпа и член-функции/член-данные, которые соответствуют определенному
      // модификатору доступа.
};


class CsharpClassUnit: public IClassUnit {
public:

public: explicit CsharpClassUnit(const std::string & name);  // конструктор.  инициализирует имя класса
    void add (const std::shared_ptr< Unit >& unit, Flags flags ) override;
    std::string  compile(unsigned int level = 0)  const override;
private: std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector < Fields > m_fields;
};



class CClassUnit: public IClassUnit {
public:

public: explicit CClassUnit(const std::string & name);
   // ~CClassUnit ();
    void add ( const std::shared_ptr< Unit >& unit, Flags flags ) override;
    std::string  compile(unsigned int level = 0)  const override;
private: std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector < Fields > m_fields;
};

class JavaClassUnit: public IClassUnit {
public:

public: explicit JavaClassUnit(const std::string & name);

    void add ( const std::shared_ptr< Unit >& unit, Flags flags ) override;
    std::string  compile(unsigned int level = 0)  const override;
private: std::string m_name;
   using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector < Fields > m_fields;
};

 const std::vector< std::string > IClassUnit::ACCESS_MODIFIERS = { "public", "protected", "private", "internal", "protected internal", "private protected" };




#endif // CLASSUNIT_H
