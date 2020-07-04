class Solution:
    
    def validIPAddress(self, IP: str) -> str:
        res = 'Neither'
        
        if IP.count(".") == 3:
            for value in IP.split("."): 
                temp_value = re.sub(r'[^0-9]', '', value)
                
                if not temp_value or not str(int(temp_value)) == value or int(temp_value) < 0 or int(temp_value) > 255:

                    return res 
            
            res = 'IPv4'
            
        if IP.count(":") == 7:
            for value in IP.split(":"): 
                temp_value = re.sub(r'[^a-fA-F0-9]', '', value)

                if not temp_value or not temp_value == value or len(temp_value) > 4 or int(temp_value, 16) < 0:

                    return res 
            
            res = 'IPv6'
        
        return res       
            