#ifndef _QUOTES_H
#define _QUOTES_H

#include "amount.h"

namespace ledger {

class quotes_by_script : public commodity_t::updater_t
{
  std::string   price_db;
  unsigned long pricing_leeway;
  bool&         cache_dirty;

 public:
  quotes_by_script(std::string   _price_db,
		   unsigned long _pricing_leeway,
		   bool&         _cache_dirty)
    : price_db(_price_db), pricing_leeway(_pricing_leeway),
      cache_dirty(_cache_dirty) {}

  virtual void operator()(commodity_t *     commodity,
			  const std::time_t date,
			  const amount_t&   price,
			  const std::time_t moment);
};

} // namespace ledger

#endif // _QUOTES_H
