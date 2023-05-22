var jsonStringify = function(object) {
    
  if (object === null) return 'null';

 
  if (typeof object === 'string') return '"' + object + '"';
  

  if (typeof object === 'number' || typeof object === 'boolean') return String(object);
  
  if (Array.isArray(object)) {
    if(object.length === 0) return "[]";
    else{
      
      const items = object.map(item => jsonStringify(item)).join(',');
      return '[' + items + ']';
    }
  }

  if (typeof object === 'object') {
    if(Object.keys(object).length === 0) return "{}";
    else{
      const keys = Object.keys(object);
      const items = keys.map(key => '"' + key + '":' + jsonStringify(object[key]));
      return '{' + items.join(',') + '}';
    }
  }
};