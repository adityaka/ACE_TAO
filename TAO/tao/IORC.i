/* -*- C++ -*- */
// $Id$

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::TAO_IOR_Manipulation (void) // default constructor
{}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::TAO_IOR_Manipulation (TAO_Stub *objref, TAO_ServantBase *_tao_servant, CORBA::Boolean _tao_collocated) // constructor
  : CORBA_Object (objref, _tao_servant, _tao_collocated)
{}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::~TAO_IOR_Manipulation (void) // destructor
{}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation_ptr
TAO_IOP::TAO_IOR_Manipulation::_nil (void)
{
  return (TAO_IOP::TAO_IOR_Manipulation_ptr)0;
}


#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION___VAR_CI_)
#define _TAO_IOP_TAO_IOR_MANIPULATION___VAR_CI_

// *************************************************************
// Inline operations for class TAO_IOP::TAO_IOR_Manipulation_var
// *************************************************************

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation_var::TAO_IOR_Manipulation_var (void) // default constructor
  : ptr_ (TAO_IOP::TAO_IOR_Manipulation::_nil ())
{}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation_var::TAO_IOR_Manipulation_var (TAO_IOP::TAO_IOR_Manipulation_ptr p)
  : ptr_ (p)
{}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation_ptr
TAO_IOP::TAO_IOR_Manipulation_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation_var::TAO_IOR_Manipulation_var (const TAO_IOP::TAO_IOR_Manipulation_var &p) // copy constructor
  : ptr_ (TAO_IOP::TAO_IOR_Manipulation::_duplicate (p.ptr ()))
{}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation_var::~TAO_IOR_Manipulation_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation_var &
TAO_IOP::TAO_IOR_Manipulation_var::operator= (TAO_IOP::TAO_IOR_Manipulation_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation_var &
TAO_IOP::TAO_IOR_Manipulation_var::operator= (const TAO_IOP::TAO_IOR_Manipulation_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = TAO_IOP::TAO_IOR_Manipulation::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation_var::operator const TAO_IOP::TAO_IOR_Manipulation_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation_var::operator TAO_IOP::TAO_IOR_Manipulation_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation_ptr
TAO_IOP::TAO_IOR_Manipulation_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation_ptr
TAO_IOP::TAO_IOR_Manipulation_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation_ptr &
TAO_IOP::TAO_IOR_Manipulation_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation_ptr &
TAO_IOP::TAO_IOR_Manipulation_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = TAO_IOP::TAO_IOR_Manipulation::_nil ();
  return this->ptr_;
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation_ptr
TAO_IOP::TAO_IOR_Manipulation_var::_retn (void)
{
  // yield ownership of managed obj reference
  TAO_IOP::TAO_IOR_Manipulation_ptr val = this->ptr_;
  this->ptr_ = TAO_IOP::TAO_IOR_Manipulation::_nil ();
  return val;
}


#endif /* end #if !defined */


#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION___OUT_CI_)
#define _TAO_IOP_TAO_IOR_MANIPULATION___OUT_CI_

// *************************************************************
// Inline operations for class TAO_IOP::TAO_IOR_Manipulation_out
// *************************************************************

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation_out::TAO_IOR_Manipulation_out (TAO_IOP::TAO_IOR_Manipulation_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = TAO_IOP::TAO_IOR_Manipulation::_nil ();
}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation_out::TAO_IOR_Manipulation_out (TAO_IOP::TAO_IOR_Manipulation_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = TAO_IOP::TAO_IOR_Manipulation::_nil ();
}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation_out::TAO_IOR_Manipulation_out (const TAO_IOP::TAO_IOR_Manipulation_out &p) // copy constructor
  : ptr_ (ACE_const_cast (TAO_IOP::TAO_IOR_Manipulation_out&,p).ptr_)
{}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation_out &
TAO_IOP::TAO_IOR_Manipulation_out::operator= (const TAO_IOP::TAO_IOR_Manipulation_out &p)
{
  this->ptr_ = ACE_const_cast (TAO_IOP::TAO_IOR_Manipulation_out&,p).ptr_;
  return *this;
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation_out &
TAO_IOP::TAO_IOR_Manipulation_out::operator= (const TAO_IOP::TAO_IOR_Manipulation_var &p)
{
  this->ptr_ = TAO_IOP::TAO_IOR_Manipulation::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation_out &
TAO_IOP::TAO_IOR_Manipulation_out::operator= (TAO_IOP::TAO_IOR_Manipulation_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation_out::operator TAO_IOP::TAO_IOR_Manipulation_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation_ptr &
TAO_IOP::TAO_IOR_Manipulation_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation_ptr
TAO_IOP::TAO_IOR_Manipulation_out::operator-> (void)
{
  return this->ptr_;
}


#endif /* end #if !defined */

// *************************************************************
// Inline operations for exception TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList
// *************************************************************

// *************************************************************
// Inline operations for exception TAO_IOP::TAO_IOR_Manipulation::NotFound
// *************************************************************

// *************************************************************
// Inline operations for exception TAO_IOP::TAO_IOR_Manipulation::Duplicate
// *************************************************************

// *************************************************************
// Inline operations for exception TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR
// *************************************************************


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_OBJECT_MANAGER_TAO_IOP_TAO_IOR_MANIPULATION_CORBA_OBJECT_CI_)
#define __TAO_OBJECT_MANAGER_TAO_IOP_TAO_IOR_MANIPULATION_CORBA_OBJECT_CI_

  // = Initialization and termination methods.
  ACE_INLINE
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object (const TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object &rhs)
    : ptr_ (rhs.ptr_),
    release_ (rhs.release_)
  {
  }

  ACE_INLINE
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object (CORBA::Object** buffer, CORBA::Boolean release)
    : ptr_ (buffer),
    release_ (release)
  {
  }

  ACE_INLINE
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object::~_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object (void)
  {
  }

  ACE_INLINE TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object &
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object::operator= (const TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object &rhs)
  {
    if (this == &rhs)
      return *this;

    if (this->release_)
    {
      CORBA::release (*this->ptr_);
      *this->ptr_ = CORBA::Object::_duplicate (*rhs.ptr_);
    }
    else
      *this->ptr_ = *rhs.ptr_;

    return *this;
  }

  ACE_INLINE TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object &
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object::operator= (CORBA::Object *p)
  // Assignment from CORBA::Object *.
  {
    if (this->release_)
    {
      CORBA::release (*this->ptr_);
      *this->ptr_ = p;
    }
    else
      *this->ptr_ = p;

    return *this;
  }

  ACE_INLINE TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object &
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object::operator= (CORBA::Object_var &p)
  // Assignment from CORBA::Object_var .
  {
    if (this->release_)
    {
      CORBA::release (*this->ptr_);
      *this->ptr_ = CORBA::Object::_duplicate(p.in());
    }
    else
      *this->ptr_ = p.in ();

    return *this;
  }

  ACE_INLINE
  CORBA::Object*
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object::operator-> (void) const
  {
    return *this->ptr_;
  }

  ACE_INLINE
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object::operator const CORBA::Object *() const // Cast (read-only).
  {
    return *this->ptr_;
  }

  ACE_INLINE
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object::operator CORBA::Object *&() // Cast.
  {
    return *this->ptr_;
  }

  ACE_INLINE CORBA::Object *
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object::in (void) const // in
  {
    return *this->ptr_;
  }

  ACE_INLINE CORBA::Object *&
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object::inout (void) // inout
  {
    return *this->ptr_;
  }

  ACE_INLINE CORBA::Object *&
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object::out (void) // out
  {
    CORBA::release (*this->ptr_);
    *this->ptr_ = CORBA::Object::_nil ();
    return *this->ptr_;
  }

  ACE_INLINE CORBA::Object *
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object::_retn (void) // retn
  {
    CORBA::Object *temp = *this->ptr_;
    *this->ptr_ = CORBA::Object::_nil ();
    return temp;
  }

#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_OBJECT_SEQUENCE_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CI_)
#define __TAO_UNBOUNDED_OBJECT_SEQUENCE_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CI_

  ACE_INLINE CORBA::Object **
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::allocbuf (CORBA::ULong nelems)
  {
    CORBA::Object **buf = 0;

    ACE_NEW_RETURN (buf, CORBA::Object*[nelems], 0);

    for (CORBA::ULong i = 0; i < nelems; i++)
      buf[i] = CORBA::Object::_nil ();

    return buf;
  }

  ACE_INLINE void
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::freebuf (CORBA::Object **buffer)
  {
    if (buffer == 0)
      return;
    delete[] buffer;
  }

  ACE_INLINE
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList (void)
  {
  }

  ACE_INLINE
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList (CORBA::ULong maximum)
    : TAO_Unbounded_Base_Sequence (maximum, TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::allocbuf (maximum))
  {
  }

  ACE_INLINE
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList (CORBA::ULong maximum,
    CORBA::ULong length,
    CORBA::Object* *value,
    CORBA::Boolean release)
  : TAO_Unbounded_Base_Sequence (maximum, length, value, release)
  {
  }

  ACE_INLINE
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList(const TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList &rhs)
    : TAO_Unbounded_Base_Sequence (rhs)
  {
    CORBA::Object **tmp1 = TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::allocbuf (this->maximum_);
    CORBA::Object ** const tmp2 = ACE_reinterpret_cast (CORBA::Object ** ACE_CAST_CONST, rhs.buffer_);

    for (CORBA::ULong i = 0; i < rhs.length_; ++i)
      tmp1[i] = CORBA::Object::_duplicate (tmp2[i]);

    this->buffer_ = tmp1;
  }

  ACE_INLINE TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList &
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::operator= (const TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList &rhs)
  {
    if (this == &rhs)
      return *this;

    if (this->release_)
    {
      CORBA::Object **tmp = ACE_reinterpret_cast (CORBA::Object **, this->buffer_);

      for (CORBA::ULong i = 0; i < this->length_; ++i)
      {
        CORBA::release (tmp[i]);
        tmp[i] = CORBA::Object::_nil ();
      }
      if (this->maximum_ < rhs.maximum_)
      {
        TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::freebuf (tmp);
        this->buffer_ = TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::allocbuf (rhs.maximum_);
      }
    }
    else
      this->buffer_ = TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::allocbuf (rhs.maximum_);

    TAO_Unbounded_Base_Sequence::operator= (rhs);

    CORBA::Object **tmp1 = ACE_reinterpret_cast (CORBA::Object **, this->buffer_);
    CORBA::Object ** const tmp2 = ACE_reinterpret_cast (CORBA::Object ** ACE_CAST_CONST, rhs.buffer_);

    for (CORBA::ULong i = 0; i < rhs.length_; ++i)
      tmp1[i] = CORBA::Object::_duplicate (tmp2[i]);

    return *this;
  }

  ACE_INLINE TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::operator[] (CORBA::ULong index) const
  // read-write accessor
  {
    ACE_ASSERT (index < this->maximum_);
    CORBA::Object ** const tmp = ACE_reinterpret_cast (CORBA::Object ** ACE_CAST_CONST, this->buffer_);
    return TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object (tmp + index, this->release_);
  }

  ACE_INLINE CORBA::Object* *
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::get_buffer (CORBA::Boolean orphan)
  {
    CORBA::Object **result = 0;
    if (orphan == 0)
    {
      // We retain ownership.
      if (this->buffer_ == 0)
      {
        result = TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::allocbuf (this->maximum_);
        this->buffer_ = result;
      }
      else
      {
        result = ACE_reinterpret_cast (CORBA::Object**, this->buffer_);
      }
    }
    else // if (orphan == 1)
    {
      if (this->release_ != 0)
      {
        // We set the state back to default and relinquish
        // ownership.
        result = ACE_reinterpret_cast(CORBA::Object**,this->buffer_);
        this->maximum_ = 0;
        this->length_ = 0;
        this->buffer_ = 0;
        this->release_ = 0;
      }
    }
    return result;
  }

  ACE_INLINE const CORBA::Object* *
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::get_buffer (void) const
  {
    return ACE_reinterpret_cast(const CORBA::Object ** ACE_CAST_CONST, this->buffer_);
  }


#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CI_)
#define _TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CI_

// *************************************************************
// Inline operations for class TAO_IOP::TAO_IOR_Manipulation::IORList_var
// *************************************************************

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::IORList_var::IORList_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::IORList_var::IORList_var (TAO_IOP::TAO_IOR_Manipulation::IORList *p)
  : ptr_ (p)
{}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::IORList_var::IORList_var (const TAO_IOP::TAO_IOR_Manipulation::IORList_var &p) // copy constructor
{
  if (p.ptr_)
    this->ptr_ = new TAO_IOP::TAO_IOR_Manipulation::IORList(*p.ptr_);
  else
    this->ptr_ = 0;
}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::IORList_var::~IORList_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation::IORList_var &
TAO_IOP::TAO_IOR_Manipulation::IORList_var::operator= (TAO_IOP::TAO_IOR_Manipulation::IORList *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation::IORList_var &
TAO_IOP::TAO_IOR_Manipulation::IORList_var::operator= (const TAO_IOP::TAO_IOR_Manipulation::IORList_var &p) // deep copy
{
  if (this != &p)
  {
    delete this->ptr_;
    this->ptr_ = new TAO_IOP::TAO_IOR_Manipulation::IORList (*p.ptr_);
  }
  return *this;
}

ACE_INLINE const TAO_IOP::TAO_IOR_Manipulation::IORList *
TAO_IOP::TAO_IOR_Manipulation::IORList_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation::IORList *
TAO_IOP::TAO_IOR_Manipulation::IORList_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::IORList_var::operator const TAO_IOP::TAO_IOR_Manipulation::IORList &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::IORList_var::operator TAO_IOP::TAO_IOR_Manipulation::IORList &() // cast
{
  return *this->ptr_;
}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::IORList_var::operator TAO_IOP::TAO_IOR_Manipulation::IORList &() const// cast
{
  return *this->ptr_;
}

ACE_INLINE
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Object_Manager<CORBA::Object,CORBA::Object_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

TAO_IOP::TAO_IOR_Manipulation::IORList_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE const TAO_IOP::TAO_IOR_Manipulation::IORList &
TAO_IOP::TAO_IOR_Manipulation::IORList_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation::IORList &
TAO_IOP::TAO_IOR_Manipulation::IORList_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size
ACE_INLINE TAO_IOP::TAO_IOR_Manipulation::IORList *&
TAO_IOP::TAO_IOR_Manipulation::IORList_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation::IORList *
TAO_IOP::TAO_IOR_Manipulation::IORList_var::_retn (void)
{
  TAO_IOP::TAO_IOR_Manipulation::IORList *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation::IORList *
TAO_IOP::TAO_IOR_Manipulation::IORList_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class TAO_IOP::TAO_IOR_Manipulation::IORList_out
// *************************************************************

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::IORList_out::IORList_out (TAO_IOP::TAO_IOR_Manipulation::IORList *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::IORList_out::IORList_out (TAO_IOP::TAO_IOR_Manipulation::IORList_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::IORList_out::IORList_out (const TAO_IOP::TAO_IOR_Manipulation::IORList_out &p) // copy constructor
  : ptr_ (ACE_const_cast (TAO_IOP::TAO_IOR_Manipulation::IORList_out&,p).ptr_)
{}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation::IORList_out &
TAO_IOP::TAO_IOR_Manipulation::IORList_out::operator= (const TAO_IOP::TAO_IOR_Manipulation::IORList_out &p)
{
  this->ptr_ = ACE_const_cast (TAO_IOP::TAO_IOR_Manipulation::IORList_out&,p).ptr_;
  return *this;
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation::IORList_out &
TAO_IOP::TAO_IOR_Manipulation::IORList_out::operator= (TAO_IOP::TAO_IOR_Manipulation::IORList *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::IORList_out::operator TAO_IOP::TAO_IOR_Manipulation::IORList *&() // cast
{
  return this->ptr_;
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation::IORList *&
TAO_IOP::TAO_IOR_Manipulation::IORList_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation::IORList *
TAO_IOP::TAO_IOR_Manipulation::IORList_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Object_Manager_TAO_IOP_TAO_IOR_Manipulation_CORBA_Object
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Object_Manager<CORBA::Object,CORBA::Object_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

TAO_IOP::TAO_IOR_Manipulation::IORList_out::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}


#endif /* end #if !defined */

ACE_INLINE CORBA::Boolean
operator<< (
    TAO_OutputCDR &,
    const TAO_IOP::TAO_IOR_Manipulation_ptr
  );
ACE_INLINE CORBA::Boolean
operator>> (
    TAO_InputCDR &,
    TAO_IOP::TAO_IOR_Manipulation_ptr &
  );

ACE_INLINE CORBA::Boolean operator<< (TAO_OutputCDR &strm, const TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList &_tao_aggregate)
{
  // first marshal the repository ID
  if (strm << _tao_aggregate._id ())
    return 1;
  else
    return 0;
}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &strm, TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList &_tao_aggregate)
{
  // retrieve  RepoID and verify if we are of that type
  char *_tao_repoID;
  if ((strm >> _tao_repoID) &&
      (_tao_aggregate._is_a (_tao_repoID)))
  {
    return 1;
  }
  else
    return 0;
}

ACE_INLINE CORBA::Boolean operator<< (TAO_OutputCDR &strm, const TAO_IOP::TAO_IOR_Manipulation::NotFound &_tao_aggregate)
{
  // first marshal the repository ID
  if (strm << _tao_aggregate._id ())
    return 1;
  else
    return 0;
}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &strm, TAO_IOP::TAO_IOR_Manipulation::NotFound &_tao_aggregate)
{
  // retrieve  RepoID and verify if we are of that type
  char *_tao_repoID;
  if ((strm >> _tao_repoID) &&
      (_tao_aggregate._is_a (_tao_repoID)))
  {
    return 1;
  }
  else
    return 0;
}

ACE_INLINE CORBA::Boolean operator<< (TAO_OutputCDR &strm, const TAO_IOP::TAO_IOR_Manipulation::Duplicate &_tao_aggregate)
{
  // first marshal the repository ID
  if (strm << _tao_aggregate._id ())
    return 1;
  else
    return 0;
}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &strm, TAO_IOP::TAO_IOR_Manipulation::Duplicate &_tao_aggregate)
{
  // retrieve  RepoID and verify if we are of that type
  char *_tao_repoID;
  if ((strm >> _tao_repoID) &&
      (_tao_aggregate._is_a (_tao_repoID)))
  {
    return 1;
  }
  else
    return 0;
}

ACE_INLINE CORBA::Boolean operator<< (TAO_OutputCDR &strm, const TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR &_tao_aggregate)
{
  // first marshal the repository ID
  if (strm << _tao_aggregate._id ())
    return 1;
  else
    return 0;
}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &strm, TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR &_tao_aggregate)
{
  // retrieve  RepoID and verify if we are of that type
  char *_tao_repoID;
  if ((strm >> _tao_repoID) &&
      (_tao_aggregate._is_a (_tao_repoID)))
  {
    return 1;
  }
  else
    return 0;
}

CORBA::Boolean  operator<< (
    TAO_OutputCDR &,
    const TAO_IOP::TAO_IOR_Manipulation::IORList &
  );
CORBA::Boolean  operator>> (
    TAO_InputCDR &,
    TAO_IOP::TAO_IOR_Manipulation::IORList &
  );

ACE_INLINE CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const TAO_IOP::TAO_IOR_Manipulation_ptr _tao_objref
  )
{
  CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

ACE_INLINE CORBA::Boolean
operator>> (
    TAO_InputCDR &strm,
    TAO_IOP::TAO_IOR_Manipulation_ptr &_tao_objref
  )
{
  ACE_TRY_NEW_ENV
  {
    CORBA::Object_var obj;
    if ((strm >> obj.inout ()) == 0)
      return 0;
    // narrow to the right type
    _tao_objref =
      TAO_IOP::TAO_IOR_Manipulation::_narrow (
          obj.in (),
          ACE_TRY_ENV
        );
    ACE_TRY_CHECK;
    return 1;
  }
  ACE_CATCHANY
  {
    // do nothing
  }
  ACE_ENDTRY;
  return 0;
}

