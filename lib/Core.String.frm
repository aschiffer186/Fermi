export module fermi::core::string; 

import fermi::containers; 
import fermi::ranges;
import fermi::memory;

export let trait string_like with container {
    public let compeval contains_substring(this, pattern : string_like) -> bool = {
        if (pattern.length() > this.length()) {
            return false;
        }
    }

    public let compeval starts_with(this, pattern : string_like) -> bool = {
        if (pattern.length() > this.length()) {
            return false;
        }

        for (lhs, rhs) in ranges:zip(this, pattern) {
            if lhs != rhs {
                return false;
            }
        }
        return true;
    }

    public let compeval ends_with(this, pattern : string_like) -> bool = {
        if (pattern.length() > this.length()) {
            return false;
        }

        for (lhs, rhs) in ranges::zip(ranges::reverse(this), ranges::reverse(pattern)) {
            if lhs != rhs {
                return false;
            }
        }
        return true;
    }
}

let struct string_iterator {
    let _data     : char* mutable;
    let _sentinel : char*;

    public let define value_type    as char; 
    public let define reference     as char&;
    public let define sentinel_type as char*;

    public let compeval new(data : char* mutable, sentinel : char*) pure -> this = {
        return string_iterator {
            _data=data, 
            _sentinel=sentinel
        };
    }

    # Required iterator methods
    public let compeval can_advance(this) pure -> bool = {
        return this.can_advance_by(1);
    }

    public let compeval can_advance_by(this, amt : int64_t) pure -> bool 
        requires amt >= 0 = {
        return memory::pointer_distance(from=this._data, to=this._sentinel) <= amt; 
    }

    public let compeval advance(this : in out) -> void = {
       this.advance_by(1);
    }

    public let compeval advance_by(this : in out, amt : int64_t) -> void = {
        if (this.can_advance_by(amt)) {
            this._data = memory::pointer_offset(from=this._data, amt=amt);
        }
    }

    public let compeval try_element(this) pure -> option<reference> = {
        if (memory::pointer_equal(from=this._data, to=this._sentinel)) {
            return optionl<reference>::none;
        }
        return option<reference>::new(*this._data);
    }

    # Note: can_advance(this) and this.can_advance() are equivlanet.
    # this.can_advance() is rewritten to string_iterator::can_advance(this);
    public let compeval element(this) pure -> reference 
        requires can_advance(this) = {
        return *this._data;
    }

    public let compeval operator-(this, rhs : string_iterator) pure -> int64_t 
        requires from_same_range(this, rhs) = {
            return memory::pointer_distance(from=this._data, to=rhs._data);
    }

    public let compeval operator==(this, rhs : string_iterator) pure -> bool 
        requires from_same_range(this, rhs) = {
            return memory::pointer_distance(from=this_.data, to=rhs._data);
    }

    # Sentinel-based iterator method 
    public let compeval sentinel() pure -> sentinel_type = {
        return _sentinel;
    }

    public let compeval from_same_range(other : string_iterator) pure -> bool = {
        return memory::pointer_equal(lhs=_sentinel, rhs=other._sentinel);
    }
}

# Underlying type of string literals, 
# but also provides view of strings, similar to 
# std::string_view in c++
export let struct string_view with string_like, range
{
    let _data  : char*;
    let _length : int64_t;

    public let define value_type as char;
    public let define reference  as char&; 
    public let define iterator   as string_iterator;

    let compeval new(data : char*, length : int64_t) pure -> this = {
        return string_view {
            _data=data, 
            _length=length,
        };
    }

    public let compeval new(str : string) pure -> this = {
        return string_view {
            _data=str.as_pointer(),
            _length=str.size()
        };
    }

    public let compeval new(str : char[]) pure -> this = {
        return string_view {
            _data=str.as_pointer(),
            _length=str.size()
        };
    }

    public let compeval begin(this) pure -> string_iterator = {
        return string_iterator::new(
            data=this._data,sentinel=memory::pointer_offset(from=this._data, amt=this._length));
    }

    public let compeval end(this) pure -> string_iterator = {
        let loc = memory::pointer_offset(from=this._data, amt=this._length);
        return string_iterator::new(data=loc, sentinel=loc);
    }

    public let compeval size(this) pure -> int64_t = {
        return _length;
    }

    public let compeval empty(this) pure -> bool = {
        return size() == 0;
    }

    
}