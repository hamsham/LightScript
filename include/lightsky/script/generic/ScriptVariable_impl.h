
namespace ls {
namespace script {



/*-----------------------------------------------------------------------------
    Variable Base Type
-----------------------------------------------------------------------------*/
/*-------------------------------------
    Variable Object Copy Assignment
-------------------------------------*/
inline
Variable& Variable::operator=(const Variable& v) {
    Scriptable::operator=(v);
    return *this;
}

/*-------------------------------------
    Variable Object Move Assignment
-------------------------------------*/
inline
Variable& Variable::operator=(Variable&& v) {
    Scriptable::operator=(std::move(v));
    return *this;
}

/*-------------------------------------
    Variable Object Base Type Query
-------------------------------------*/
inline
script_base_t Variable::get_script_type() const {
    return script_base_t::VARIABLE;
}

/*-----------------------------------------------------------------------------
    Extended Variable Template Type
-----------------------------------------------------------------------------*/
/*-------------------------------------
    Variable Object Type Destructor
-------------------------------------*/
template <hash_t hashId, typename type>
Variable_t<hashId, type>::~Variable_t() {
}

/*-------------------------------------
    Variable Object Type Constructor
-------------------------------------*/
template <hash_t hashId, typename type>
Variable_t<hashId, type>::Variable_t() :
    Variable{},
    data{}
{}

/*-------------------------------------
    Variable Object Type Copy Constructor
-------------------------------------*/
template <hash_t hashId, typename type>
Variable_t<hashId, type>::Variable_t(const Variable_t& v) :
    Variable{v},
    data{v.data}
{}

/*-------------------------------------
    Variable Object Type Move Constructor
-------------------------------------*/
template <hash_t hashId, typename type>
Variable_t<hashId, type>::Variable_t(Variable_t&& v) :
    Variable{std::move(v)},
    data{std::move(v.data)}
{}

/*-------------------------------------
    Variable Object Type Copy Assignment
-------------------------------------*/
template <hash_t hashId, typename type>
Variable_t<hashId, type>& Variable_t<hashId, type>::operator=(const Variable_t& v) {
    Variable::operator=(v);
    data = v.data;
    return *this;
}

/*-------------------------------------
    Variable Object Type Move Assignment
-------------------------------------*/
template <hash_t hashId, typename type>
Variable_t<hashId, type>& Variable_t<hashId, type>::operator=(Variable_t&& v) {
    Variable::operator=(std::move(v));
    data = std::move(v.data);
    return *this;
}

/*-------------------------------------
    Variable Object Type Data Loading
-------------------------------------*/
template <hash_t hashId, typename type>
bool Variable_t<hashId, type>::load(std::istream& istr, VariableMap_t&, FunctorMap_t&) {
    istr >> data;
    return istr.good() || istr.eof();
}

/*-------------------------------------
    Variable Object Type Data Saving
-------------------------------------*/
template <hash_t hashId, typename type> inline
bool Variable_t<hashId, type>::save(std::ostream& ostr) const {
    ostr << data;
    return ostr.good();
}

/*-------------------------------------
    Variable Object Type RTTI
-------------------------------------*/
template <hash_t hashId, typename type> inline
hash_t Variable_t<hashId, type>::get_script_subtype() const {
    return hashId;
}



} // end script namespace
} // end ls namespace
